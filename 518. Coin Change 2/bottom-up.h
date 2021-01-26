//
// Created by samik on 1/25/2021.
//

#ifndef DP_GFG_BOTTOM_UP_H
#define DP_GFG_BOTTOM_UP_H
#include <vector>

using namespace std;

/**
 * This is similar to 0/1 knapsack problem, where we need the number of combinations
 * that add upto a certain number.
 * */

int change(int amount, vector<int>& coins) {
    vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, 0));

    dp[0][0] = 1;

    for(int i = 1; i < dp.size(); i++) {
        for(int j = 0; j < dp[0].size(); j++) {
            dp[i][j] += dp[i - 1][j];

            if(j >= coins[i - 1]) {
                dp[i][j] += dp[i][j - coins[i - 1]];
            }
        }
    }

    return dp.back().back();
}


#endif //DP_GFG_BOTTOM_UP_H
