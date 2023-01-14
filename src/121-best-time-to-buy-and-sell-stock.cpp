#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices);
    int maxProfit1(vector<int> &prices);
};

int Solution::maxProfit(vector<int> &prices)
{
    int min = INT32_MAX, ans = 0;

    for (auto &i : prices) {
        min = std::min(min, i);
        ans = std::max(ans, i - min);
    }

    return ans;
}

int Solution::maxProfit1(vector<int> &prices)
{
    const int len = prices.size();
    vector<int[2]> dp(len);

    dp[0][0] = -prices[0];
    dp[0][1] = 0;

    for (int i = 1; i < len; i++) {
        dp[i][0] = std::max(dp[i - 1][0], -prices[i]);
        dp[i][1] = std::max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
    }

    return max(dp[len - 1][0], dp[len - 1][1]);
}

int main(int argc, char *argv[])
{
    vector<int> a = {7, 1, 5, 3, 6, 4};
    Solution s;
    cout << s.maxProfit(a) << endl;
    cout << s.maxProfit1(a) << endl;
    return 0;
}
