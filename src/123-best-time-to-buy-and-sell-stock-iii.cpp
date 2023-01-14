#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices);
};

/*
 * 0. 到第 i 天一直没有操作
 * 1. 已经第一次买入
 * 2. 已经第一次卖出
 * 3. 已经第二次买入
 * 4. 已经第二次卖出
 */
int Solution::maxProfit(vector<int> &prices)
{
    const int len = prices.size();
    vector<int[5]> dp(len);
    int ans = 0;

    dp[0][0] = 0;
    dp[0][1] = -prices[0];
    dp[0][2] = 0;
    dp[0][3] = -prices[0];
    dp[0][4] = 0;

    for (int i = 1; i < len; i++) {
        dp[i][0] = dp[i - 1][0];
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i]);
        dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] - prices[i]);
        dp[i][4] = max(dp[i - 1][4], dp[i - 1][3] + prices[i]);
    }

    ans = max(ans, max(dp[len - 1][4], dp[len - 1][2]));

    return ans;
}

int main(int argc, char *argv[])
{
    vector<int> a = {3, 3, 5, 0, 0, 3, 1, 4};
    Solution s;
    cout << s.maxProfit(a) << endl;
    return 0;
}
