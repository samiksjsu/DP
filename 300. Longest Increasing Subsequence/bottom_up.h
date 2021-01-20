//
// Created by samik on 1/20/2021.
//

#ifndef DP_GFG_BOTTOM_UP_H
#define DP_GFG_BOTTOM_UP_H
#include <vector>
#include <iostream>

using namespace std;

int lengthOfLIS(vector<int>& nums) {
    vector<int> dp(nums.size(), 1);
    int result = 0;

    /**
     * @param result -> The larget LIS formed in the complete dp[] array.
     * @param i -> The number whose capacity to form LIS is currently being tested
     * @param j-> The number with which number i is trying to pair with. dp[j] consists of the LIS formed at index j.
     * @param dp[] -> The array that stores the largest LIS formed by the number at that index.
     *                All values are initialized with 1, since each number is a subsequence it itself of length 1.
     * */

    for(int i = 1; i < nums.size(); i++) {

        int count = 0;

        for(int j = 0; j < i; j++) {
            if(nums[i] > nums[j]) {
                count = max(count, dp[j] + 1);
            }
        }

        dp[i] = max(dp[i], count);
        result = max(result, dp[i]);
    }

    return result;
}

#endif //DP_GFG_BOTTOM_UP_H
