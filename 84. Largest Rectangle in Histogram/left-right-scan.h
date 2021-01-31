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
 * 1. For each index, find the furthest index, both on right and left, till where the histogram of current height
 *    can extend.
 * 2. The current height histogram can extend till it finds another histogram that is smaller than current.
 * 3. We use a stack to get the left and right furthest index and store it in the left and right vector.
 * 4. Logic for finding furthest:
 *      a. Pop the indexes from the stack whose heights[idx] is greater than the current.
 *      b. If the stack is empty, that means the current i is the smallest and it can extend till the end. So, for the
 *         current i we mark either 0 or right.size() - 1;
 *      c. Else, we now have the next smallest idx at the top of the stack that has heights[st.top()] < heights[i].
 *         Hence, we mark the ith point with st.top() / idx + 1.
 *      d. Finally we push the current i into the stack to be considered further.
 *  5. Finally, the max area that includes the ith histogram = heights[i] * breath till which this histogram can extend
 *     on both sides of the vector.
 *     => maxArea(i) = heights[i] * right[i] - left[i] + 1;
 *  6. When recording the max area that includes the current histogram, we calculate the global max = max(res, maxArea(i))
 * */

int largestRectangleArea(vector<int>& heights) {
    vector<int> left(heights.size(), 0);
    vector<int> right(heights.size(), 0);
    stack<int> leftSt;
    stack<int> rightSt;

    for(int i = 0; i < left.size(); i++) {

        while(!leftSt.empty() && heights[leftSt.top()] >= heights[i]) leftSt.pop();

        if(leftSt.empty()) {
            left[i] = 0;
        } else {
            left[i] = leftSt.top() + 1;
        }

        leftSt.push(i);
    }


    for(int i = right.size() - 1; i >= 0; i--) {
        while(!rightSt.empty() && heights[rightSt.top()] >= heights[i]) rightSt.pop();

        if(rightSt.empty()) {
            right[i] = right.size() - 1;
        } else {
            right[i] = rightSt.top() - 1;
        }

        rightSt.push(i);
    }

    int res = INT_MIN;

    for(int i = 0; i < heights.size(); i++) {
        heights[i] = (right[i] - left[i] + 1) * heights[i];

        res = max(res, heights[i]);
    }

    return res;
}

#endif //DP_GFG_LEFT_RIGHT_SCAN_H
