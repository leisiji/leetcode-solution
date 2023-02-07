#include <algorithm>
#include <cstdint>
#include <utility>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxProduct(vector<int>& nums);
};

/* 1. 若当前是正数，和正数相乘则可以得到较大数
 * 2. 若当前是负数，和较小数可以得到较大的数 */
int Solution::maxProduct(vector<int>& nums)
{
    const int len = nums.size();
    vector<int> max(len), min(len);  // 表示第 i 个元素子数组的最大或最小乘积

    max[0] = nums[0], min[0] = nums[0];

    for (int i = 1; i < len; i++) {
        max[i] = std::max(nums[i] * max[i - 1], std::max(nums[i], nums[i] * min[i - 1]));
        min[i] = std::min(nums[i] * min[i - 1], std::min(nums[i], nums[i] * max[i - 1]));
    }

    int ans = nums[0];
    for (int i = 1; i < len; i++) {
        ans = std::max(ans, max[i]);
    }

    return ans;
}
