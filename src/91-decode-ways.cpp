#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    int numDecodings(string s);
};

/* 动态规划 dp[i] =
 * 1. if s[i] 不为 0 + 1， dp[i - 1]
 * 1. if s[i], s[i - 1] 转换成功 + 1， dp[i - 2] */
int Solution::numDecodings(string s)
{
    const int len = s.size();

    if (len == 1) {
        return (s[0] != '0') ? 1 : 0;
    }

    vector<int> dp(len, 0);

    const auto c1 = s[0], c2 = s[1];
    if (c1 != '0') {
        dp[0] = 1;
        dp[1] = (c2 != '0') ? 1 : 0;
    }
    if (c1 == '1' || (c1 == '2' && (c2 >= '0' && c2 <= '6'))) {
        dp[1] += 1;
    }

    for (int i = 2; i < len; i++) {
        const auto c1 = s[i], c2 = s[i - 1];;
        if (c1 != '0') {
            dp[i] += dp[i - 1];
        }
        if (c2 == '1' || (c2 == '2' && (c1 >= '0' && c1 <= '6'))) {
            dp[i] += dp[i - 2];
        }
    }

    return dp[len - 1];
}

int main(int argc, char *argv[])
{
    Solution s;
    cout << s.numDecodings("226") << endl;                                            // 3
    cout << s.numDecodings("32323453534353453535432656565") << endl;                  // 8
    cout << s.numDecodings("111111111111111111111111111111111111111111111") << endl;  // 1836311903
    cout << s.numDecodings("122222021212") << endl;
    return 0;
}
