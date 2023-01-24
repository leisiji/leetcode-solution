#include <iostream>
#include <vector>

#include "listnode.hpp"

class Solution
{
public:
    int numTrees(int n);
};

int Solution::numTrees(int n)
{
    std::vector<int> dp(n + 1);
    dp[0] = 1; // 通过 dp[1] 就可以推导出来 dp[0] 的值

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i] += dp[j - 1] * dp[i - j];
        }
    }

    return dp[n];
}

int main(int argc, char *argv[])
{
    Solution s;
    std::cout << s.numTrees(3) << std::endl;  // 5
    return 0;
}
