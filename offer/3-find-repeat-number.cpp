#include <type_traits>
#include <vector>

using namespace std;

class Solution {
public:
    int findRepeatNumber(vector<int>& nums);
};

int Solution::findRepeatNumber(vector<int> &nums)
{
    const int len = nums.size();

    for (int i = 0; i < len;) {
        auto tmp = nums[i];
        if (tmp == i) {
            i++;
            continue;
        } else if (tmp == nums[tmp]) {
            return tmp;
        } else {
            swap(nums[tmp], nums[i]);
        }
    }

    return nums[0];
}
