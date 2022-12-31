#include <vector>
#include <assert.h>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target);
};

int Solution::searchInsert(vector<int>& nums, int target)
{
    int low = -1, high = nums.size(), mid, tmp;

    while (low + 1 < high) {
        mid = (low + high) >> 1;

        tmp = nums[mid];
        if (tmp == target) {
            return mid;
        } else if (tmp > target) {
            high = mid;
        } else {
            low = mid;
        }
    }

    return high;
}

int main(int argc, char *argv[])
{
    vector<int> a = {1,3,5,6};
    Solution s;
    assert(s.searchInsert(a, 5) == 2);
    assert(s.searchInsert(a, 2) == 1);
    assert(s.searchInsert(a, 7) == 4);
    return 0;
}

