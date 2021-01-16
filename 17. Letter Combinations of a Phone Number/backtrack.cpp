#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<string> result;

void helper(vector<string> &words, int start, string curr) {
    if(start == words.size()) {
        if(curr.length()) result.push_back(curr);
        return;
    }

    string temp = words[start];

    for(auto itr = temp.begin(); itr < temp.end(); itr++) {
        curr.push_back(*itr);
        helper(words, start + 1, curr);
        curr.pop_back();
    }
}

vector<string> letterCombinations(string digits) {
    unordered_map<int, string> m;

    m[2] = "abc";
    m[3] = "def";
    m[4] = "ghi";
    m[5] = "jkl";
    m[6] = "mno";
    m[7] = "pqrs";
    m[8] = "tuv";
    m[9] = "wxyz";

    vector<string> words;

    for(auto itr = digits.begin(); itr < digits.end(); itr++) {
        words.push_back(m[*itr - '0']);
    }

    helper(words, 0, "");

    return result;
}
