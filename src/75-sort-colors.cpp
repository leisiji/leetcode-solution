#include <vector>

#include "listnode.hpp"

using namespace std;

class Solution
{
public:
    void sortColors(vector<int>& nums);
};

/* (left, right) 为表示 1 的区间 */
void Solution::sortColors(vector<int>& nums)
{
    const int len = nums.size();
    int left = -1, right = len, cur = 0;

    /* 由于 2 需要放到未遍历的位置，因此需要判断替换后的值是否为 0，cur 不能自增 */
    while (cur < right) {
        int tmp = nums[cur];
        if (tmp == 2) {
            swap(nums[right - 1], nums[cur]);
            right--;
            continue;
        } else if (tmp == 0) {
            swap(nums[left + 1], nums[cur]);
            left++;
        }
        cur++;
    }
}

static void test(vector<int>& a)
{
    Solution s;
    s.sortColors(a);
    print_vec(a);
}

int main(int argc, char* argv[])
{
    vector<int> a = {2, 0, 2, 1, 1, 0};
    vector<int> b = {0, 0, 0};
    vector<int> c = {2, 2, 2};
    vector<int> d = {1, 1, 1};
    vector<int> e = {1};
    vector<int> f = {1, 2, 0};
    test(a);
    test(b);
    test(c);
    test(d);
    test(e);
    test(f);
    return 0;
}
