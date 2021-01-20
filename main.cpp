#include <iostream>
#include <vector>
#include <algorithm>
#include "300. Longest Increasing Subsequence/bottom_up.h"


using namespace std;

int cherryPickup(vector<vector<int>> &grid) {

    int n = grid.size(), m = grid[0].size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (grid[i - 1][j - 1] == -1) {
                dp[i][j] = -1;
                continue;
            }

            int top = dp[i - 1][j];
            int left = dp[i][j - 1];
            int temp = 0;

            if (top > left) {
                temp = dp[i - 1][j];
            } else {
                temp = dp[i][j - 1];
            }

            int val = grid[i - 1][j - 1] + temp;
            dp[i][j] = val;
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {


        }
    }
    return dp.back().back();
}

int result = 0;
vector<string> paths;

void helper(vector<int> &nums, int currSum, int S, int start, string path) {
    if (start == nums.size()) {
        if (currSum == S) {
            result++;
            paths.push_back(path);
        }
        return;
    }

    for (int i = start; i < nums.size(); i++) {
        currSum += nums[i];
        path.push_back('+');
        path.push_back(nums[i] + '0');
        helper(nums, currSum, S, i + 1, path);
        currSum -= nums[i];
        path.pop_back();
        path.pop_back();

        currSum -= nums[i];
        path.push_back('-');
        path.push_back(nums[i] + '0');
        helper(nums, currSum, S, i + 1, path);
        currSum += nums[i];
        path.pop_back();
        path.pop_back();
    }

}

int main() {


    vector<int> nums = {1, 3, 6, 7, 9, 4, 10, 5, 6};
    cout << lengthOfLIS(nums) << endl;
    cout << "Hello" << endl;
}
