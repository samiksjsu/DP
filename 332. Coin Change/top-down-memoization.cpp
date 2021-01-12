#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int helper(vector<int> &coins, int amountToFind, unordered_map<int, int> &memory) {

    if(amountToFind == 0) return 0;

    if(memory[amountToFind]) return memory[amountToFind];

    int minCoins = INT_MAX;

    for(int &coin: coins) {
        if(coin > amountToFind) continue;

        int val = helper(coins, amountToFind - coin, memory);

        minCoins = min(minCoins, val);
    }

    minCoins = minCoins == INT_MAX ? minCoins : minCoins + 1;
    memory[amountToFind] = minCoins;
    return minCoins;
}

int coinChange(vector<int>& coins, int amount) {

    unordered_map<int, int> memory;

    int result =  helper(coins, amount, memory);

    return result == INT_MAX ? -1 : result;
}

