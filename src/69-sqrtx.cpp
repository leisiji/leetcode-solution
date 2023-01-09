#include <assert.h>
#include <iostream>

using namespace std;

class Solution
{
public:
    int mySqrt(int x);
};

/* 本题可以使用二分查找或牛顿迭代法 */
int Solution::mySqrt(int x)
{
    if (x == 0 || x == 1) {
        return 0;
    }

    int left = 0, right = x;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        int tmp = x / mid; // 防止溢出
        if (tmp == mid) {
            return mid;
        } else if (tmp > mid) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return right;
}

int main(int argc, char *argv[])
{
    Solution s;
    assert(s.mySqrt(2147395599) == 46339);
    assert(s.mySqrt(4) == 2);
    assert(s.mySqrt(256) == 16);
    return 0;
}
