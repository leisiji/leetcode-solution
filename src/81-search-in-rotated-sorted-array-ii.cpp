#include <vector>
#include <assert.h>
#include <iostream>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target);
};

static inline bool move_left(int cur, int last, int target)
{
    if (cur < last) {
        if (target > cur && target <= last) {
            return true;
        }
    } else {
        if (target > cur || target <= last) {
            return true;
        }
    }

    return false;
}

bool Solution::search(vector<int> &nums, int target)
{
    const int len = nums.size();
    int left = 0, right = len - 1;
    int last = nums.back();

    if (last == target) {
        return true;
    }

    while (left <= right) {
        // 相比 33 题，增加跳过相同元素的操作
        if (left + 1 <= right && nums[left] == nums[left+1]) {
            left++;
            continue;
        }
        if (right - 1 >= left && nums[right] == nums[right-1]) {
            right--;
            continue;
        }
        int mid = (left + right) >> 1;
        int tmp = nums[mid];
        if (tmp == target) {
            return true;
        } else if (move_left(tmp, last, target)) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return false;
}

int main (int argc, char *argv[])
{
    vector<int> a = {2,5,6,0,0,1,2};
    vector<int> b = {1,0,1,1,1};
    Solution s;
    assert(s.search(a, 6));
    assert(!s.search(a, 3));
    assert(s.search(b, 0));
    return 0;
}
