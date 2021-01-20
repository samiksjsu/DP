//
// Created by samik on 1/18/2021.
//

#include "backtrack.h"


void backtrack(string &s, int start, string curr, int n, vector<string> &result, unordered_map<char, int> &m) {
    if(curr.length() == n) {
        result.push_back(curr);
        return;
    }

    for(int i = 0; i < s.length(); i++) {

        cout << m[s[i]] << endl;

        char last = curr.back();
        int lastCharPos = m[last];

        char charToPush = s[i];
        int charToPushPos = m[s[i]];

        if(charToPushPos < lastCharPos) continue;

        curr.push_back(s[i]);
        backtrack(s, i + 1, curr, n, result, m);
        curr.pop_back();
    }
}

int countVowelStringsDP(int n) {
    vector<vector<int>>dp(n + 1, vector<int>(6));
    for (int i = 1; i <= n; ++i)
        for (int k = 1; k <= 5; ++k)
            dp[i][k] = dp[i][k - 1] + (i > 1 ? dp[i - 1][k] : 1);
    return dp[n][5];
}

int countVowelStrings(int n) {
    vector<string> result;
    unordered_map<char, int> m;
    m['a'] = 0; m['e'] = 1; m['i'] = 2; m['o'] = 3; m['u'] = 4;

    string s = "aeiou";

    backtrack(s, 0, "", n, result, m);

    cout << countVowelStringsDP(n) << endl;

    cout << result.size() << endl;
    return result.size();
}