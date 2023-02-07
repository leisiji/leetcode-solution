#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int findMin(vector<int> &nums);
};

int Solution::findMin(vector<int> &nums)
{
    const int pivot = nums[0];

    if (pivot <= nums.back()) {
        return pivot;
    }
    int left = 0, right = nums.size() - 1;

    while (left < right) {
        int mid = (left + right) >> 1;
        auto tmp = nums[mid];
        if (tmp >= pivot) {
            left = mid + 1;
        } else {
            right = mid;
            // 这里就是和其他二分不同之处，因为小于第一个数还可能是最小值
        }
    }

    return nums[left];
}

int main(int argc, char *argv[])
{
    vector<int> a = {3, 4, 5, 1, 2};
    vector<int> b = {3, 4, 5, 1};
    vector<int> c = {3, 4, 5, 0, 1, 2};
    Solution s;
    cout << s.findMin(a) << endl;
    cout << s.findMin(b) << endl;
    cout << s.findMin(c) << endl;
    return 0;
}
