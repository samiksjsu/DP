#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int main() {

    string s = "226";

    int n = s.length();

    if(n == 0) return 0;

    vector<int> dp(n + 1, 0);

    dp[0] = 1;
    dp[1] = s[1] == '0' ? 0 : 1;

    for(int i = 2; i <= s.length(); i++) {
        int first = stoi(s.substr(i - 1, 1));
        int second = stoi(s.substr(i - 2, 2));

        if(first >= 1 && first <= 9) {
            dp[i] += dp[i - 1];
        }

        if(second >= 10 && second <= 26) {
            dp[i] += dp[i - 2];
        }
    }

    return dp.back();
    cout << "Hello" << endl;
}
