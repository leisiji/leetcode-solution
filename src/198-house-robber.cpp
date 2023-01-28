#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    int rob(vector<int>& nums);
};

int Solution::rob(vector<int>& nums)
{
    const int len = nums.size();
    vector<int[2]> dp(len);

    dp[0][0] = 0;
    dp[0][1] = nums[0];

    for (int i = 1; i < len; i++) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
        dp[i][1] = dp[i - 1][0] + nums[i];
    }

    return max(dp[len - 1][0], dp[len - 1][1]);
}

int main (int argc, char *argv[])
{
    vector<int> a = {2,7,9,3,1};
    vector<int> b = {1,2,3,1};
    Solution s;
    cout << s.rob(a) << endl; // 12
    cout << s.rob(b) << endl; // 4
    return 0;
}
