#include <numeric>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string reverseLeftWords(string s, int n);
};

/* 和 leetcode 189 相同 */
string Solution::reverseLeftWords(string s, int n)
{
    const int len = s.size(), step = len - n % len;
    if (step == 0) {
        return s;
    }

    const auto loop = gcd(step, len);
    for (int i = 0; i < loop; i++) {
        int start = step + i;
        auto prev = s[start];
        int j = start;
        do {
            j = (j + step) % len;
            auto tmp = s[j];
            s[j] = prev;
            prev = tmp;
        } while (j != start);
    }

    return s;
}

int main(int argc, char *argv[])
{
    Solution s;
    string a = "123456";
    cout << s.reverseLeftWords(a, 2) << endl;
    cout << s.reverseLeftWords(a, 4) << endl;
    cout << s.reverseLeftWords(a, 1) << endl;
    return 0;
}
