#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    string intToRoman(int num);
};

/* 1 <= num <= 3999 */
string Solution::intToRoman(int num)
{
    string res;
    int s;

    static const char *thousand[] = {"", "M", "MM", "MMM"};
    static const char *hundred[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    static const char *tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    static const char *ones[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

    res.append(thousand[num / 1000]);
    num = num % 1000;
    res.append(hundred[num / 100]);
    num = num % 100;
    res.append(tens[num / 10]);
    num = num % 10;
    res.append(ones[num]);

    return res;
}

int main(int argc, char *argv[])
{
    Solution s;
    std::cout << s.intToRoman(1994) << std::endl;
    return 0;
}
