//
// Created by samik on 1/19/2021.
//

#ifndef DP_GFG_BOTTOM_UP_H
#define DP_GFG_BOTTOM_UP_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);

    if(sum % 2 != 0) return false;

    sum /= 2;

    int m = nums.size();

    vector<vector<bool>> dp(m + 1, vector<bool> (sum + 1, false));

    dp[0][0] = true;

    for(int i = 1; i <= m; i++) {
        for(int j = 0; j <= sum; j++) {
            int num = nums[i - 1];

            if(j == 0) {
                dp[i][j] = true;
            } else {
                if(j < num) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j - num] || dp[i - 1][j];
                }
            }
        }
    }

    return dp.back().back();
}


#endif //DP_GFG_BOTTOM_UP_H
