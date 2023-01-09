#include <algorithm>
#include <string>
#include <iostream>
#include <assert.h>
#include <string.h>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b);
};

static inline int update(string &s, char sum, int k)
{
    int cur;

    if (sum >= 2) {
        s[k] = '0' + sum - 2;
        cur = 1;
    } else {
        s[k] = '0' + sum;
        cur = 0;
    }

    return cur;
}

string Solution::addBinary(string a, string b)
{
    int m = a.length(), n = b.length();
    int i = m - 1, j = n - 1;
    char cur = 0;
    int olen = std::max(m, n), k = olen - 1;
    string out(olen, 0);

    out.reserve(olen);

    while (i >= 0 && j >= 0) {
        char val_a = a[i] - '0', val_b = b[j] - '0';
        char sum = val_a + val_b + cur;
        cur = update(out, sum, k);
        i--, j--, k--;
    }

    while (i >= 0) {
        char val_a = a[i] - '0';
        char sum = val_a + cur;
        cur = update(out, sum, k);
        i--, k--;
    }
    while (j >= 0) {
        char val_b = b[j] - '0';
        char sum = val_b + cur;
        cur = update(out, sum, k);
        j--, k--;
    }

    if (cur > 0) {
        string tmp;
        tmp.push_back('1');
        for (auto &h : out) {
            tmp.push_back(h);
        }
        tmp[0] = '1';
        return tmp;
    }

    return out;
}

int main (int argc, char *argv[])
{
    Solution s;
    auto ret = s.addBinary("110", "1");
    assert(ret == "111");
    ret = s.addBinary("11", "1");
    assert(ret == "100");
    return 0;
}
