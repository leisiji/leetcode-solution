#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    int find_nth(vector<int>& nums1, int start1, vector<int>& nums2, int start2, int k);

public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);
};

int Solution::find_nth(vector<int>& nums1, int start1, vector<int>& nums2, int start2, int k)
{
    // 保证 nums1 的大小小于 nums2，因为后面会先判断 nums1 是否到达末尾
    if (nums1.size() - start1 > nums2.size() - start2) {
        return find_nth(nums2, start2, nums1, start1, k);
    }

    // 第一个数组已经空了，证明中位数在第二个数组
    if (nums1.size() == start1) {
        return nums2[start2 + k - 1];
    }

    // k = 1 时，取两数组第一个元素的最小值
    if (k == 1) {
        return min(nums1[start1], nums2[start2]);
    }

    int n1 = min(static_cast<int>(nums1.size()), start1 + k / 2);
    int n2 = start2 + k - k / 2;

    if (nums1[n1 - 1] < nums2[n2 - 1]) {
        return find_nth(nums1, n1, nums2, start2, k - (n1 - start1));
    }

    return find_nth(nums1, start1, nums2, n2, k - (n2 - start2));
}

// 找中位数转化为找第 k 大的数, k = (m + n) / 2
double Solution::findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
    int k = nums1.size() + nums2.size();

    if (k % 2 != 0) {
        return find_nth(nums1, 0, nums2, 0, k / 2 + 1);
    }

    int l = find_nth(nums1, 0, nums2, 0, k / 2);
    int r = find_nth(nums1, 0, nums2, 0, k / 2 + 1);

    return (l + r) / 2.0;
}

int main(int argc, char* argv[])
{
    Solution s;

    vector<int> nums1 = {1, 2}, nums2 = {3, 4};
    std::cout << s.findMedianSortedArrays(nums1, nums2) << std::endl;

    nums1 = {1, 2, 3}, nums2 = {4, 5};
    std::cout << s.findMedianSortedArrays(nums1, nums2) << std::endl;

    return 0;
}
