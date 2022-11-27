#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2);
};

string Solution::multiply(string num1, string num2)
{
    const int len1 = num1.length();
    const int len2 = num2.length();
    int carrier = 0;
    string tmp;

    for (int i = 1; i <= len1 + len2; i++) {
        int mul = carrier;
        for (int j = 1; j < i + 1; j++) {
            int a = (j <= len1) ? (num1.at(len1 - j) - '0') : 0;
            int index = i + 1 - j;
            int b = (index <= len2) ? (num2.at(len2 - index) - '0') : 0;
            mul += a * b;
        }
        if (mul >= 10) {
            carrier = mul / 10;
            tmp.push_back((mul % 10) + '0');
        } else {
            carrier = 0;
            tmp.push_back(mul + '0');
        }
    }

    string res;
    int i = tmp.length() - 1;

    for (; i >= 0; i--) {
        if (tmp.at(i) != '0') {
            break;
        }
    }

    if (i < 0) {
        return "0";
    }

    for (; i >= 0; i--) {
        res.push_back(tmp.at(i));
    }

    return res;
}

int main (int argc, char *argv[])
{
    Solution s;
    cout << s.multiply("123", "456") << endl;
    cout << s.multiply("99", "0001") << endl;
    cout << s.multiply("999999999999999999999999999999999", "999999999999999999999999999999999") << endl;
    cout << s.multiply("0", "111") << endl;
    return 0;
}
