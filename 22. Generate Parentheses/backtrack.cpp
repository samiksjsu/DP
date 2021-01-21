#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/**
 * Reason for Backtrack - Since we want the parentheses themselves and not just the number.
 *
 * Logic:
 *      a. If n == 3, that means 3 opening and 3 closing brackets. Hence, when str.length == n * 2, we terminate.
 *      b. Otherwise, first we add an opening bracket and then we add a closing bracket.
 *      c. Open should be less than 'n' and the closing ones should only be added iff there is an complementing opening
 *         bracket. Hence, closing should always happen if that is less than open.
 *
 *      @param list -> All the valid bracket combinations
 *      @param str -> Combination for the current recursion
 * */

void backtrack(vector<string> &list, string str, int open, int close, int max) {

    if (str.length() == max * 2) {
        list.push_back(str);
        return;
    }

    if (open < max)
        backtrack(list, str + "(", open + 1, close, max);
    if (close < open)
        backtrack(list, str + ")", open, close + 1, max);
}

vector<string> generateParenthesis() {

    int n = 3;
    vector<string> list;
    backtrack(list, "", 0, 0, n);
    return list;
}
