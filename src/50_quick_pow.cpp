#include <iostream>
using namespace std;
// 每次不是偶数的时候乘上 x
class Solution
{
public:
    double myPow(double x, int n)
    {
        double res = 1.0;
        long num = n;

        if (n < 0) {
            num = -num;
            x = 1 / x;
        } else if (n == 0) {
            return 1;
        } else if (n == 1) {
            return x;
        }

        if (x == 1.0 || x == 0.0) {
            return x;
        }

        while (num > 0) {
            if (num % 2 != 0) {
                res *= x;
            }
            x *= x;
            num = num / 2;
        }

        return res;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    cout << s.myPow(2, 7) << endl;

    return 0;
}
