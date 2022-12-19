#include <cwchar>
#include <iostream>
#include <vector>

#include "listnode.h"

using namespace std;

/*
 * 题干的意思是：找出这个数组排序出的所有数中，刚好比当前数大的那个数
 * 比如当前 nums =
 * [1,2,3]。这个数是123，找出1，2，3这3个数字排序可能的所有数，排序后，比123大的那个数 也就是132
 * 如果当前 nums =
 * [3,2,1]。这就是1，2，3所有排序中最大的那个数，那么就返回1，2，3排序后所有数中最小的那个，也就是1，2，3
 * -> [1,2,3]
 */
class Solution
{
public:
    void nextPermutation(vector<int> &nums);
};

void Solution::nextPermutation(vector<int> &nums)
{
    const int len = nums.size();
    int i = len - 2, j = len - 1;

    // 找到第一个 A[i] < A[i+1] 的索引；注意，这一步后，[i+1, end] 必然是降序
    for (; i >= 0; i--) {
        if (nums[i] < nums[i + 1]) {
            break;
        }
    }

    /* 还要求下一个数增加的幅度尽可能的小，将一个尽可能小的「大数」 与前面的「小数」交换
     * 比如 123465，下一个排列应该把 5 和 4 交换而不是把 6 和 4 交换 */
    if (i >= 0) {
        while (nums[i] >= nums[j]) {
            j--;
        }
        swap(nums[i], nums[j]);
    }

    // 将「大数」换到前面后，需要将「大数」后面的所有数重置为升序
    for (i = i + 1, j = len - 1; i < j; i++, j--) {
        swap(nums[i], nums[j]);
    }
}

int main(int argc, char *argv[])
{
    vector<int> a = {1, 2, 3, 4, 3, 7, 9, 5};
    vector<int> c = {3,2,1};

    Solution s;
    s.nextPermutation(a);
    print_vec(a);

    s.nextPermutation(c);
    print_vec(c);

    return 0;
}
