#include <stdint.h>

#include <algorithm>
#include <iostream>
#include <vector>

#include "assert.h"

using namespace std;

class Solution
{
public:
    int minSubArrayLen(int target, vector<int>& nums);
};

int Solution::minSubArrayLen(int target, vector<int>& nums)
{
    int left = 0, right = 0, min = INT32_MAX;
    const int len = nums.size();
    int sum = 0;

    for (int right = 0; right < len; right++) {
        sum += nums[right];
        while (left <= right && sum >= target) {
            sum -= nums[left];
            min = std::min(min, right - left + 1);
            left++;
        }
    }

    return (min == INT32_MAX) ? 0 : min;
}

int main(int argc, char* argv[])
{
    vector<int> a = {2, 3, 1, 2, 4, 3};
    Solution s;
    assert(s.minSubArrayLen(7, a) == 2);
    return 0;
}
