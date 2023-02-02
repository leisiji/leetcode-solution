#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include "listnode.hpp"

using namespace std;

class Solution
{
public:
    int minCut(string s);
};

static inline bool is_palindrome(const string_view &s)
{
    int left = 0, right = s.size() - 1;

    while (left < right) {
        if (s[left] != s[right]) {
            return false;
        }
        left++, right--;
    }

    return true;
}

/* f(i) 为最小分割次数，会有 2 种情况：
 * 1. 第 i 个已经可以构成回文串，则无需分割，f(i) = 0
 * 2. 第 i 个无法分割，向左找到一个点 j，恰好使端点右边构成一个回文串且右边已经可以分割为回文串 */
int Solution::minCut(string s)
{
    const int len = s.size();
    vector<int> dp(len, INT32_MAX - 1);

    // [j,i] 是否为回文串
    vector<vector<bool>> palindrome(len, vector<bool>(len, false));
    string_view sv = s;

    for (int i = 0; i < len; i++) {
        for (int j = 0; j < i; j++) {
            if (is_palindrome(sv.substr(j, i - j + 1))) {
                palindrome[i][j] = true;
            }
        }
        palindrome[i][i] = true;
    }

    for (int i = 0; i < len; i++) {
        if (palindrome[i][0]) {
            dp[i] = 0;
        } else {
            for (int j = 1; j <= i; j++) {
                if (palindrome[i][j]) {
                    dp[i] = min(dp[i], dp[j - 1] + 1);
                }
            }
        }
    }

    return dp[len - 1];
}

int main(int argc, char *argv[])
{
    string a = "aab";
    Solution s;
    cout << s.minCut(a) << endl;
    return 0;
}
