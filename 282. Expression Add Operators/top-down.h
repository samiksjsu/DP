//
// Created by samik on 1/21/2021.
//

#ifndef DP_GFG_TOP_DOWN_H
#define DP_GFG_TOP_DOWN_H


using namespace std;



vector<string> addOperators(string num, int target) {

    vector<string> result;
    vector<int> nums;

    for(char &c: num) {
        nums.push_back(c - '0');
    }

    return result;
}

#endif //DP_GFG_TOP_DOWN_H
