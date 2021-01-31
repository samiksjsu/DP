//
// Created by samik on 1/30/2021.
//

#ifndef DP_GFG_LEFT_RIGHT_SCAN_H
#define DP_GFG_LEFT_RIGHT_SCAN_H

#include <vector>
#include <stack>

using namespace std;

/**
 * Logic:
 * 1. Compare to ques 84, construct the largest histogram for each of the rows.
 * 2. Once the histogram of the row is constructed, send it to the function to calculate the max rect in the histogram
 * */

int largestRectangleArea(vector<int> &heights);

int maximalRectangle(vector<vector<char>> &matrix) {

    if (matrix.size() == 0 || matrix[0].size() == 0) return 0;

    int res = 0;
    vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));

    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {

            if (i == 0) {
                dp[i][j] = (matrix[i][j] - '0');
            } else {

                if (matrix[i][j] - '0' == 0) continue;

                dp[i][j] = dp[i - 1][j] + (matrix[i][j] - '0');
            }
        }

        int tempRes = largestRectangleArea(dp[i]);
        res = max(res, tempRes);
    }

    return res;

}

int largestRectangleArea(vector<int> &heights) {
    vector<int> left(heights.size(), 0);
    vector<int> right(heights.size(), 0);
    stack<int> leftSt;
    stack<int> rightSt;

    for (int i = 0; i < left.size(); i++) {

        while (!leftSt.empty() && heights[leftSt.top()] >= heights[i]) leftSt.pop();

        if (leftSt.empty()) {
            left[i] = 0;
        } else {
            left[i] = leftSt.top() + 1;
        }

        leftSt.push(i);
    }


    for (int i = right.size() - 1; i >= 0; i--) {
        while (!rightSt.empty() && heights[rightSt.top()] >= heights[i]) rightSt.pop();

        if (rightSt.empty()) {
            right[i] = right.size() - 1;
        } else {
            right[i] = rightSt.top() - 1;
        }

        rightSt.push(i);
    }

    int res = INT_MIN;

    vector<int> result(heights.size(), 0);

    for(int i = 0; i < heights.size(); i++) {
        result[i] = (right[i] - left[i] + 1) * heights[i];

        res = max(res, result[i]);
    }

    return res;
}

void driver() {
    vector<vector<char>> matrix{{'0', '0', '0', '0', '0', '0', '1'},
                                {'0', '0', '0', '0', '1', '1', '1'},
                                {'1', '1', '1', '1', '1', '1', '1'},
                                {'0', '0', '0', '1', '1', '1', '1'}};

    maximalRectangle(matrix);
}

#endif //DP_GFG_LEFT_RIGHT_SCAN_H
