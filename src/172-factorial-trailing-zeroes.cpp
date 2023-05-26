class Solution
{
public:
    int trailingZeroes(int n);
};

/* 可以发现一个规律只有 2 和 5 相乘才可以在末尾得到 0，
 * 因此转换成求 1-n 中 2 和 5 一对的因子数，此时的时间复杂度是 O(n)，
 * 但其实还有一个规律：
 * 1. 在 2 个能被 5 整除的数中间，有且只有一个能被 2 整除的数，
 * 2. 因此质因子 5 的个数不会大于质因子 2 的个数，主需要统计 5 的个数 */

// 未优化前的写法：O(n)
int trailingZeroes(int n)
{
    int ans = 0;
    for (int i = 5; i <= n; i += 5) {
        for (int x = i; x % 5 == 0; x /= 5) {
            ++ans;
        }
    }
    return ans;
}

// 优化后：O(log n)
int Solution::trailingZeroes(int n)
{
    int ans = 0;
    while (n) {
        n /= 5;
        ans += n;
    }
    return ans;
}
