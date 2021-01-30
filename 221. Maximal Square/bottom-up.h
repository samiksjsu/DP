//
// Created by samik on 1/29/2021.
//

#ifndef DP_GFG_BOTTOM_UP_H
#define DP_GFG_BOTTOM_UP_H
#include <vector>
using namespace std;

int maximalSquare(vector<vector<char>>& matrix) {
    vector<vector<int>> dp(matrix.size() + 1, vector<int> (matrix[0].size() + 1, 0));
    int result = INT_MIN;

    for(int i = 1; i < dp.size(); i++) {
        for(int j = 1; j < dp[0].size(); j++) {
            if(matrix[i - 1][j - 1] == '1') {
                dp[i][j] = 1 + min({dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]});

                result = max(result, dp[i][j] * dp[i][j]);
            }
        }
    }

    return result == INT_MIN ? 0 : result;
}

#endif //DP_GFG_BOTTOM_UP_H
