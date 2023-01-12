#include <assert.h>
#include <string.h>

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Solution
{
public:
    bool canPartition1(vector<int> &nums);
    bool canPartition(vector<int> &nums);
};

bool Solution::canPartition1(vector<int> &nums)
{
    int sum = 0;
    for (auto &i : nums) {
        sum += i;
    }
    if (sum % 2 != 0) {
        return false;
    }

    // 只要找到子集和为 sum / 2，就可以认为这个集合满足题目条件
    int target = sum / 2;
    const int len = nums.size();
    vector<vector<bool>> dp(len + 1, vector<bool>(target + 1, false));

    for (int i = 0; i < len; i++) {
        dp[i][0] = true;  // 和为 0，不取任何一个数字满足，则为 true
    }

    for (int i = 1; i < dp.size(); i++) {
        for (int j = 1; j < dp[0].size(); j++) {
            int tmp = nums[i - 1];
            if (j >= tmp) {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - tmp];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[len][target];
}

bool Solution::canPartition(vector<int> &nums)
{
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if ((sum & 1) == 1) {
        return false;
    }

    const int target = sum / 2;
    const int len = nums.size();
    vector<int> dp(target + 1, 0);

    for (int i = 1; i < len; i++) {
        const int tmp = nums[i];
        for (int j = target; j >= tmp; j--) {
            if (dp[target] == target) {  // 判断最终结果提前结束
                return true;
            }
            dp[j] = max(dp[j], dp[j - tmp] + tmp);
        }
    }

    return (dp[target] == target);
}

int main(int argc, char *argv[])
{
    vector<int> a = {1, 5, 11, 5};
    vector<int> b = {1, 2, 3, 5};
    vector<int> c = {1, 2, 5};
    Solution s;
    assert(s.canPartition(a) == true);
    assert(s.canPartition(b) == false);
    assert(s.canPartition(c) == false);
    return 0;
}
