#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n);
};

int Solution::findMaxForm(vector<string> &strs, int m, int n)
{
    const int len = strs.size();
    vector<int[2]> data(len);

    for (int i = 0; i < len; i++) {
        int x = 0, y = 0;
        for (auto &j : strs[i]) {
            if (j == '0') {
                x++;
            } else {
                y++;
            }
        }
        data[i][0] = x;
        data[i][1] = y;
    }

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 0; i < len; i++) {
        const int x = data[i][0], y = data[i][1];
        for (int j = m; j >= x; j--) {
            for (int k = n; k >= y; k--) {
                dp[j][k] = max(dp[j][k], dp[j - x][k - y] + 1);
            }
        }
    }

    return dp[m][n];
}

int main (int argc, char *argv[])
{
    vector<string> a = {"10", "0001", "111001", "1", "0"};
    Solution s;
    cout << s.findMaxForm(a, 5, 3) << endl;
    return 0;
}
