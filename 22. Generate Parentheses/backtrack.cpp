#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void backtrack(vector<string> &list, string str, int open, int close, int max){

    if(str.length() == max*2){
        list.push_back(str);
        return;
    }

    if(open < max)
        backtrack(list, str+"(", open+1, close, max);
    if(close < open)
        backtrack(list, str+")", open, close+1, max);
}

vector<string> generateParenthesis() {

    int n = 3;
    vector<string> list;
    backtrack(list, "", 0, 0, n);
    return list;
}
