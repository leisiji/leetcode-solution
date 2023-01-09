#include <assert.h>
#include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n);
};

/* f(n) = f(n-1) + f(n-2) */
int Solution::climbStairs(int n)
{
    if (n <= 2) {
        return n;
    }

    int prev1 = 1, prev2 = 2, ans = 0;
    n = n - 2;

    while (n > 0) {
        ans = prev1 + prev2;
        prev1 = prev2;
        prev2 = ans;
        n--;
    }

    return ans;
}

int main(int argc, char *argv[])
{
    Solution s;
    assert(s.climbStairs(10) == 89);
    return 0;
}
