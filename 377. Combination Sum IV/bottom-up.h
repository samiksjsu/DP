//
// Created by samik on 1/26/2021.
//

#ifndef DP_GFG_BOTTOM_UP_H
#define DP_GFG_BOTTOM_UP_H
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int combinationSum4(vector<int> nums, int target) {
    vector<int> dp (target + 1);
    dp[0] = 1;
    for (int i = 1; i < dp.size(); i++) {
        for (int j = 0; j < nums.size(); j++) {

            int rem = i - nums[j];

            if (rem >= 0) {
                dp[i] += dp[rem];
            }
        }
    }

    return dp[target];
}

#endif //DP_GFG_BOTTOM_UP_H
