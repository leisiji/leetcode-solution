#include <vector>
#include "listnode.h"

using namespace std;

class Solution
{
public:
    int removeDuplicates1(vector<int>& nums);
    int removeDuplicates(vector<int>& nums);
};

// 有序数组，原地删除重复出现的元素，使得出现次数超过两次的元素只出现两次，并返回新数组的长度
int Solution::removeDuplicates1(vector<int>& nums)
{
    int end = 0, cur, count = 1, i = 0;
    const int len = nums.size();

    while (i < len) {
        int tmp = nums[i];
        count = 1;
        cur = tmp;
        nums[end] = tmp;
        end++;
        i++;
        while (i < len && nums[i] == cur) {
            if (count < 2) {
                nums[end] = nums[i];
                end++;
                count++;
            }
            i++;
        }
    }

    return end;
}

// 快慢指针解法：slow - 1 为输出数组的末尾索引；fast 指向要检查的元素
int Solution::removeDuplicates(vector<int>& nums)
{
    const int len = nums.size();

    if (len <= 2) {
        return len;
    }

    int slow = 2, fast = 2;

    while (fast < len) {
        if (nums[slow - 2] != nums[fast]) {
            nums[slow] = nums[fast];
            slow++;
        }
        fast++;
    }

    return slow;
}

static void test(vector<int> &a)
{
    Solution s;
    auto ret = s.removeDuplicates(a);
    a.resize(ret);
    print_vec(a);
}

int main(int argc, char* argv[])
{
    vector<int> a = {1,1,1,2,2,3};
    vector<int> b = {1,2,3,4};
    vector<int> c = {1,1,1,1,2,2,2,2,2,3,3,3,4};
    test(a);
    test(b);
    test(c);
    return 0;
}
