#include <iostream>
using namespace std;
class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0) {
            return false;
        }
        uint64_t tmp = 0;
        uint64_t origin = x;

        while (x > 0) {
            tmp = tmp * 10 + x % 10;
            x = x / 10;
        }

        return origin == tmp;
    }
};
int main(int argc, char *argv[])
{
    Solution s;
    std::cout << s.isPalindrome(2147483647) << std::endl;
    return 0;
}
