//
// Created by samik on 1/19/2021.
//

#ifndef DP_GFG_TWO_H
#define DP_GFG_TWO_H

#include <vector>
#include <iostream>
#include <numeric>

using namespace std;

int splitIntoTwo(vector<int> &nums) {
    int count = 0;

    int j = 0;
    int rightSum = accumulate(nums.begin(), nums.end(), 0);
    int leftSum = 0;

    while(j < nums.size()) {
        leftSum += nums[j];
        rightSum -= nums[j];

        if(leftSum > rightSum) count++;
        j++;

    }

    return count;
}

#endif //DP_GFG_TWO_H
