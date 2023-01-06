#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s);
};

int Solution::lengthOfLastWord(string s)
{
    int len = 0, prev_len = 0;

    for (auto &i : s) {
        if (i != ' ') {
            len++;
        } else {
            if (len != 0) {
                prev_len = len;
            }
            len = 0;
        }
    }

    return (len == 0) ? prev_len : len;
}

int main (int argc, char *argv[])
{
    string str = "hello world";
    Solution s;
    cout << s.lengthOfLastWord(str) << endl;
    string str1 = "hello world   ";
    cout << s.lengthOfLastWord(str1) << endl;
    cout << s.lengthOfLastWord("  ") << endl;
    return 0;
}
