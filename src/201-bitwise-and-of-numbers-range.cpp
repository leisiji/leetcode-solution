#include <iostream>

using namespace std;

class Solution
{
public:
    int rangeBitwiseAnd(int left, int right);
};

int Solution::rangeBitwiseAnd(int left, int right)
{
    int sum = left;

    for (int i = left + 1; i <= right; i++) {
        sum = sum & i;
        if (sum == 0) {
            return 0;
        }
    }

    return sum;
}

int main(int argc, char *argv[])
{
    Solution s;
    cout << s.rangeBitwiseAnd(5, 7) << endl;
    cout << s.rangeBitwiseAnd(1, 2147483647) << endl;
    return 0;
}
