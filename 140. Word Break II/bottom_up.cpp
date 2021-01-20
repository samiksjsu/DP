//
// Created by samik on 1/18/2021.
//

#include "bottom_up.h"

vector<string> wordBreak(string s, vector<string>& wordDict) {

    vector<string> result;
    vector<string> words;
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    vector<int> dp(s.length() + 1, 0);
    dp[0] = 1;

    for(int i = 1; i <= s.length(); i++) {
        for(int j = 0; j < i; j++) {
            string currSub = s.substr(j, i - j);

            if(dict.find(currSub) != dict.end() && dp[j] == 1) {
                dp[i] = 1;
                words.push_back(currSub);
            }
        }
    }

    return result;
}
