#include <iostream>
#include <vector>
#include <algorithm>
#include "85. Maximal Rectangle/left-right-scan.h"


using namespace std;

int cherryPickup(vector<vector<int>> &grid) {

    int n = grid.size(), m = grid[0].size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (grid[i - 1][j - 1] == -1) {
                dp[i][j] = -1;
                continue;
            }

            int top = dp[i - 1][j];
            int left = dp[i][j - 1];
            int temp = 0;

            if (top > left) {
                temp = dp[i - 1][j];
            } else {
                temp = dp[i][j - 1];
            }

            int val = grid[i - 1][j - 1] + temp;
            dp[i][j] = val;
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {


        }
    }
    return dp.back().back();
}

int main() {

    driver();
    cout << "Hello" << endl;
}
