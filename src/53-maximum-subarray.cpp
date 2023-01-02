#include <algorithm>
#include <vector>
#include <iostream>
#include <assert.h>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums);
};

// 动态规划，先写出状态转移方程：
// f(i) = f(i-1) + nums[i]
// 或 f(i) = nums[i]，此时 f(i-1) < 0，即 f(i-1) 不会对 f(i) 的和有贡献
int Solution::maxSubArray(vector<int> &nums)
{
    int sum = 0;
    int ans = nums[0];

    for (auto &i : nums) {
        if (sum > 0) {
            sum += i;
        } else {
            sum = i;
        }
        ans = max(ans, sum);
    }

    return ans;
}

int main(int argc, char *argv[])
{
    vector<int> a = {-2,1,-3,4,-1,2,1,-5,4};
    vector<int> b = {5,4,-1,7,8};
    vector<int> c = {-2,1};
    vector<int> d = {2,0,-3,2,1,0,1,-2};
    Solution s;
    assert(s.maxSubArray(a) == 6);
    assert(s.maxSubArray(b) == 23);
    assert(s.maxSubArray(c) == 1);
    assert(s.maxSubArray(d) == 4);
    return 0;
}
