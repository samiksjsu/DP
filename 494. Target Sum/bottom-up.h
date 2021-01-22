//
// Created by samik on 1/21/2021.
//

#ifndef DP_GFG_BOTTOM_UP_H
#define DP_GFG_BOTTOM_UP_H
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int findTargetSumWays(vector<int>& nums, int S) {
    int sum = accumulate(nums.begin(), nums.end(), 0);

    if (sum < S || (sum + S) % 2 != 0) {
        return 0;
    }

    int target = (sum + S) / 2;
    vector<vector<int>> dp(nums.size(), vector<int>(target + 1, 0));
    dp[0][0] = nums[0] == 0 ? 2 : 1;
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = 0; j <= target; ++j) {

            if(i == 0) {
                if(j == 0) continue;
                dp[i][j] = nums[i] == j ? 1 : 0;

            } else {
                dp[i][j] = dp[i - 1][j];
                if (nums[i] <= j) {
                    dp[i][j] += dp[i - 1][j - nums[i]];
                }
            }
        }
    }
    return dp[nums.size() - 1][target];
}


#endif //DP_GFG_BOTTOM_UP_H
