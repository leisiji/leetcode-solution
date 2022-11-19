#include <iostream>

class Solution {
public:
    int reverse(int x);
};

/* 这题需要注意的就是溢出的情况 */
int Solution::reverse(int x)
{
    int a, b, ans = 0;

    while (x != 0) {
        // 因为在后面，ans 需要乘以 10，因此不能超过边界除以 10
        if (ans < INT32_MIN / 10 || ans > INT32_MAX / 10) {
            return 0;
        }
        a = x / 10;
        b = x % 10;
        x = a;
        ans = ans * 10 + b;
    }

    return ans;
}

int main (int argc, char *argv[])
{
    Solution s;
    std::cout << s.reverse(123) << std::endl;
    std::cout << s.reverse(-1234566) << std::endl;
    return 0;
}
