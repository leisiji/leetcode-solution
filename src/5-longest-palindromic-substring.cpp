#include <string.h>

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    // O(n)
    string longestPalindrome(string s);

    // O(n^2): dp
    string longestPalindrome1(string s);
};

string Solution::longestPalindrome(string s)
{
    if (s.size() <= 2) {
        return s;
    }

    return "";
}

/* 在已经知道 [l,r] 是否为回文的前提下，判断 [l-1, r+1] 是否为回文，
 * 只需要知道 s[l-1] == s[r+1] 是否成立；动态规划加速了暴力解法的判断；
 * 暴力：划定一个区域，比较区域中心点两侧的字符串 */
string Solution::longestPalindrome1(string s)
{
    auto size = s.size();

    if (size < 2) {
        return s;
    }

    bool dp[s.size()][s.size()];  // 保存了 [i, j] 是否为回文
    int max_len = 1;
    int max_start = 0;

    memset(dp, true, sizeof(dp));

    for (int i = 1; i < size; i++) {
        for (int j = 0; j < i; j++) {
            if (s[i] == s[j]) {
                if (i - j <= 2) {
                    dp[j][i] = true;
                } else {
                    dp[j][i] = dp[j + 1][i - 1];
                }
            } else {
                dp[j][i] = false;
            }

            if (dp[j][i] && max_len < i - j + 1) {
                max_len = i - j + 1;
                max_start = j;
            }
        }
    }

    return s.substr(max_start, max_len);
}

int main(int argc, char *argv[])
{
    Solution s;
    std::cout << s.longestPalindrome1("ac") << std::endl;
    return 0;
}
