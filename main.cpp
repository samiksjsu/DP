#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <unordered_map>

using namespace std;

vector<string> result;

void helper(vector<string> &words, int start, string curr) {
    if(start == words.size()) {
        result.push_back(curr);
        return;
    }

    string temp = words[start];

    for(auto itr = temp.begin(); itr < temp.end(); itr++) {
        curr.push_back(*itr);
        helper(words, start + 1, curr);
        curr.pop_back();
    }
}

int main() {

    string digits = "23";
    unordered_map<int, string> m;

    m[1] = "abc";
    m[2] = "def";
    m[3] = "ghi";
    m[4] = "jkl";
    m[5] = "mno";
    m[6] = "pqrs";
    m[7] = "tuv";
    m[8] = "wxyz";

    vector<string> words;

    for(auto itr = digits.begin(); itr < digits.end(); itr++) {
        words.push_back(m[*itr - '0']);
    }

    helper(words, 0, "");

    cout << "Hello" << endl;
}
