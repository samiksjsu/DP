//
// Created by samik on 1/18/2021.
//

#ifndef DP_GFG_BACKTRACK_H
#define DP_GFG_BACKTRACK_H
#include "../all_headers.h"

using namespace std;

int countVowelStrings(int n);
void backtrack(string &s, int start, string curr, int n,vector<string> &result);
int countVowelStringsDP(int n);

#endif //DP_GFG_BACKTRACK_H
