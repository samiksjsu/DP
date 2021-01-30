//
// Created by samik on 1/21/2021.
//

#ifndef DP_GFG_TOP_DOWN_H
#define DP_GFG_TOP_DOWN_H


using namespace std;

void helper(string &num, int idx, string tempStr, int temp, int target, vector<string> &result) {
    if(idx == num.size() && temp == target) {
        result.push_back(tempStr);
        return;
    } else if(idx >= num.size()) {
        return;
    }

    // call for addition
    tempStr.push_back('+');
    tempStr.push_back(num[idx]);
    helper(num, idx + 1, tempStr, temp + (num[idx] - '0'), target, result);
    tempStr.pop_back();
    tempStr.pop_back();

    // call for substraction
    tempStr.push_back('-');
    tempStr.push_back(num[idx]);
    helper(num, idx + 1, tempStr, temp - (num[idx] - '0'), target, result);
    tempStr.pop_back();
    tempStr.pop_back();

    // call for multiplication
    tempStr.push_back('*');
    tempStr.push_back(num[idx]);
    helper(num, idx, tempStr, temp * (num[idx] - '0'), target, result);
    tempStr.pop_back();
    tempStr.pop_back();
}

vector<string> addOperators() {

    vector<string> result;
    string num = "123"; int target = 6;
    helper(num, 1, to_string(num[0] - '0'), (num[0] - '0'), target, result);

    return result;
}

#endif //DP_GFG_TOP_DOWN_H
