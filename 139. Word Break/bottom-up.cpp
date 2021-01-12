#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool solution() {
    string s = "leetcode";
    unordered_set<string> dict {"leet", "code"};

    vector<bool> f(s.length() + 1);
    f[0] = true;

    for(int i=1; i <= s.length(); i++){
        for(int j=0; j < i; j++){

            string curr = s.substr(j, i - j);

            if(f[j] && dict.find(curr) != dict.end()){
                f[i] = true;
                break;
            }
        }
    }

    cout << f[s.length()] << endl;
}

