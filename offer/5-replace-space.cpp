#include <string>

using namespace std;

class Solution {
public:
    string replaceSpace(string s);
    string replaceSpace1(string s);
};

/* 每个空格替换成 "%20" */
string Solution::replaceSpace(string s)
{
    string out;

    for (auto &i: s) {
        if (i == ' ') {
            out.append("%20");
        } else {
            out.push_back(i);
        }
    }

    return out;
}

/* 原地修改 */
string Solution::replaceSpace1(string s)
{
    int count = 0;
    const int len = s.size();

    for (auto &i : s) {
        if (i == ' ') {
            count++;
        }
    }

    int nlen = len + 2 * count;
    s.resize(nlen);

    int j = nlen - 1;
    for (int i = len - 1; i >= 0 ; i--) {
        if (s[i] == ' ') {
            s[j--] = '0';
            s[j--] = '2';
            s[j--] = '%';
        } else {
            s[j--] = s[i];
        }
    }


    return s;
}
