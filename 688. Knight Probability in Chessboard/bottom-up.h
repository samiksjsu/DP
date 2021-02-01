//
// Created by samik on 2/1/2021.
//

#ifndef DP_GFG_BOTTOM_UP_H
#define DP_GFG_BOTTOM_UP_H

#include <vector>
using namespace std;

/**
 * Logic:
 * 1. If curr[i][j] != 0, that means the knight was here and can now move from 8 different places
 *    having i, j as curr start.
 * 2. This newI and newJ will be for the next move and hence we store their probability in the 'next' matrix;
 * 3. We keep on doing this till we exhaust the number of moves.
 * 4. After the moves have ben exhausted, we return the total of all the prob in the curr matrix.
 * */

vector<pair<int, int>> directions {{2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-1, 2}, {1, 2}, {-2, 1}, {-2, -1}};

double knightProbability(int N, int K, int r, int c) {
    vector<vector<double>> curr(N, vector<double> (N, 0.0));
    vector<vector<double>> next(N, vector<double> (N, 0.0));
    curr[r][c] = 1;

    for(int mov = 1; mov <= K; mov++) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(curr[i][j] > 0.0) {
                    for(auto &direction: directions) {
                        int newX = direction.first + i;
                        int newY = direction.second + j;

                        if(newX >= 0 && newX < N && newY >= 0 && newY < N) {
                            next[newX][newY] += curr[i][j] / 8.0;
                        }
                    }
                }
            }
        }
        curr = next;
        next = vector(N, vector<double> (N, 0.0));
    }

    double res = 0.0;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            res += curr[i][j];
        }
    }

    return res;
}

void driver688() {
    double res = knightProbability(3, 2, 0, 0);

    cout << res << endl;
}

#endif //DP_GFG_BOTTOM_UP_H
