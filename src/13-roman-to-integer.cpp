#include <cstdio>
#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>

using namespace std;

class Solution
{
public:
    int romanToInt(string s);

private:
    int value(char s);
};

int Solution::value(char s)
{
    static unordered_multimap<char, int> map = {
        make_pair('I', 1),   make_pair('V', 5),   make_pair('X', 10),   make_pair('L', 50),
        make_pair('C', 100), make_pair('D', 500), make_pair('M', 1000),
    };

    return map.find(s)->second;
}

/* 解法的核心在于：遍历时要同时向前看一个元素 */
int Solution::romanToInt(string s)
{
    const int len = s.length();
    int prev = value(s.at(0));
    int res = prev;

    for (int i = 1; i < len; i++) {
        int v = value(s.at(i));
        if (prev == 1) {
            if (v == 5) {
                v = 4;
                res -= prev;
                prev = 0;
            } else if (v == 10) {
                v = 9;
                res -= prev;
                prev = 0;
            }
            prev = v;
        } else if (prev == 10) {
            if (v == 50) {
                v = 40;
                res -= prev;
                prev = 0;
            } else if (v == 100) {
                v = 90;
                res -= prev;
                prev = 0;
            }
            prev = v;
        } else if (prev == 100) {
            if (v == 500) {
                v = 400;
                res -= prev;
                prev = 0;
            } else if (v == 1000) {
                v = 900;
                res -= prev;
                prev = 0;
            }
            prev = v;
        } else {
            prev = v;
        }
        res += v;
    }

    return res;
}

int main(int argc, char *argv[])
{
    Solution s;
    cout << s.romanToInt("III") << endl;
    cout << s.romanToInt("IV") << endl;
    cout << s.romanToInt("LVIII") << endl;
    cout << s.romanToInt("MCMXCIV") << endl;
    cout << s.romanToInt("MDCCCLXXXIV") << endl;
    return 0;
}
