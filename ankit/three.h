
#ifndef DP_GFG_THREE_H
#define DP_GFG_THREE_H

#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<pair<int, int>> directions {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void helper(vector<vector<int>> &grid, pair<int, int> curr, int &count) {

    grid[curr.first][curr.second] = 0;

    for(auto &direction: directions) {
        int newX = curr.first + direction.first;
        int newY = curr.second + direction.second;

        if(newX >= 0 && newX < grid.size() && newY >= 0 && newY < grid[0].size() && grid[newX][newY] == 1) {
            helper(grid, {newX, newY}, count + 1);
        }
    }
}

vector<int> onesGroup(vector<vector<int>> &grid, vector<int> queries) {

    if(grid.size() == 0 || grid[0].size() == 0) return vector<int>();

    // 1st int = number of elements, 2nd int = number of groups
    unordered_map<int, int> m;
    for(int i = 0; i < grid.size(); i++) {
        for(int j = 0; j < grid[i].size(); j++) {
            if(grid[i][j] == 1) {
                int count = 1;
                helper(grid, {i, j}, count);
                m[count]++;
            }
        }
    }

    vector<int> result(queries.size(), 0);
    for(int i = 0; i < queries.size(); i++) {
        result[i] = m[queries[i]];
    }

    return result;

}

#endif //DP_GFG_THREE_H
