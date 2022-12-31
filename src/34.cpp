#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    int lowerbound(vector<int>& nums, int bound);

public:
    vector<int> searchRange(vector<int>& nums, int target);
};

int Solution::lowerbound(vector<int>& nums, int bound)
{
    int low = 0, high = nums.size() - 1, mid;

    // 这里用闭区间的写法 [low, high]
    while (low <= high) {
        mid = (low + high) >> 1;
        if (nums[mid] < bound) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return low;
}

vector<int> Solution::searchRange(vector<int>& nums, int target)
{
    int low = lowerbound(nums, target);
    if (low == nums.size() || nums[low] != target) {
        return {-1, -1};
    }

    int high = lowerbound(nums, target + 1) - 1;

    return {low, high};
}

int main (int argc, char *argv[])
{
    vector<int> a = {5,7,7,8,8,10};
    Solution s;
    auto ret = s.searchRange(a, 8);
    cout << ret[0] << "," << ret[1] << endl;
    ret = s.searchRange(a, 10);
    cout << ret[0] << "," << ret[1] << endl;
    ret = s.searchRange(a, 7);
    cout << ret[0] << "," << ret[1] << endl;
    ret = s.searchRange(a, 6);
    cout << ret[0] << "," << ret[1] << endl;

    vector<int> b = {5};
    ret = s.searchRange(b, 10);
    cout << ret[0] << "," << ret[1] << endl;
    ret = s.searchRange(b, 5);
    cout << ret[0] << "," << ret[1] << endl;
    return 0;
}
