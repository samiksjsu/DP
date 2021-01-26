//
// Created by samik on 1/22/2021.
//

#ifndef DP_GFG_BACKTRACK_H
#define DP_GFG_BACKTRACK_H
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

vector<int> col;
vector<int> diag1;
vector<int> diag2;

void dfs(vector<vector<string>> &res, vector<string> &list, int row, int n) {
    if(row == n) {
        res.push_back(list);
        return;
    }

    for (int i = 0; i < n; ++i) {
        if(col[i] || diag1[row + i] || diag2[row - i]) {
            continue;
        }

        string temp(n, '.');
        temp[i] = 'Q';
        list.push_back(temp);
        col[i] = 1;
        diag1[row + i] = 1;
        diag2[row - i] = 1;

        dfs(res, list, row + 1, n);

        list.pop_back();
        col[i] = 0;
        diag1[row + i] = 0;
        diag2[row - i] = 0;
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> res;
    vector<string> list;

    col.resize(n);
    diag1.resize(n);
    diag2.resize(n);

    dfs(res, list, 0, n);

    return res;
}

#endif //DP_GFG_BACKTRACK_H
