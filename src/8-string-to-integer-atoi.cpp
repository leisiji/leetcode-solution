#include <cstdint>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int myAtoi(string s);
};

/* int 范围是 (-pow(2, 31), pow(2, 31) - 1) */
int Solution::myAtoi(string s)
{
    int res = 0;
    bool negative = false;
    int i = 0, j = 0;

    // jump over leading space
    for (i = 0; i < s.size(); i++) {
        if (s.at(i) == ' ') {
            continue;
        } else {
            break;
        }
    }

    if (i == s.size()) {
        return 0;
    }

    // signess
    if (s.at(i) == '-') {
        negative = true;
        i++;
    } else if (s.at(i) == '+') {
        i++;
    }

    for (; i < s.size(); i++) {
        auto c = s.at(i);
        if (c >= '0' && c <= '9') {
            j = (c - '0') * (negative ? -1 : 1);
            if (negative) {
                if (res < (INT32_MIN / 10) || (res == (INT32_MIN / 10) && j <= (INT32_MIN % 10))) {
                    return INT32_MIN;
                }
            } else {
                if (res > (INT32_MAX / 10) || (res == (INT32_MAX / 10) && j >= (INT32_MAX % 10))) {
                    return INT32_MAX;
                }
            }
            res = 10 * res + j;
        } else {
            break;
        }
    }

    return res;
}

int main (int argc, char *argv[])
{
    Solution s;
    std::cout << s.myAtoi("+12233") << std::endl;
    std::cout << s.myAtoi("-12233") << std::endl;
    std::cout << s.myAtoi("12233") << std::endl;
    std::cout << s.myAtoi(" -12233 adadda") << std::endl;
    std::cout << s.myAtoi("2147483648") << std::endl; // pow(2, 31)
    std::cout << s.myAtoi("2147483649") << std::endl; // pow(2, 31) + 1
    std::cout << s.myAtoi("-2147483648") << std::endl; // -pow(2, 31)
    std::cout << s.myAtoi("-91283472332") << std::endl; // -pow(2, 31)
    std::cout << s.myAtoi("+91283472332") << std::endl; // -pow(2, 31)
    std::cout << s.myAtoi("   -42") << std::endl; // -pow(2, 31)
    return 0;
}
