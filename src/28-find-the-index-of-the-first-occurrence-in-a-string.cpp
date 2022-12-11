#include <string.h>

#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle);
    int strStr1(string haystack, string needle);
};

/* 朴素解法 */
int Solution::strStr(string haystack, string needle)
{
    const int len = haystack.size();
    const int nsize = needle.size();

    if (nsize == 1) {
        auto c = needle.at(0);
        for (int n = 0; n < len; n++) {
            if (c == haystack.at(n)) {
                return n;
            }
        }
    }

    if (len == nsize) {
        int n = 0;
        for (n = 0; n < len; n++) {
            if (haystack.at(n) != needle.at(n)) {
                break;
            }
        }
        if (n == len) {
            return 0;
        }
    }

    for (int i = 0; i < len - nsize; i++) {
        int j = i;
        int k = 0;
        for (; k < nsize; j++, k++) {
            if (haystack.at(j) != needle.at(k)) {
                break;
            }
        }
        if (k == nsize) {
            return i;
        }
    }

    return -1;
}

/* 使用 libc 的 strstr 非常快（KMP），可以击败 100% */
int Solution::strStr1(string haystack, string needle)
{
    auto s = strstr(haystack.c_str(), needle.c_str());
    return s != nullptr ? (s - haystack.c_str()) : -1;
}

int main(int argc, char *argv[])
{
    Solution s;
    cout << s.strStr("hello", "ll") << endl;
    return 0;
}
