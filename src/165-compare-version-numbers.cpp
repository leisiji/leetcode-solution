#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    int compareVersion(string version1, string version2);
};

int Solution::compareVersion(const string version1, const string version2)
{
    const char *n1 = version1.data(), *n2 = version2.data();

    while (true) {
        char *tmp;
        uint32_t v1 = 0;
        if (n1[0] != 0) {
            v1 = strtoul(n1, &tmp, 10);
            if (*tmp != 0) {
                n1 = tmp + 1;
            } else {
                n1 = tmp;
            }
        }

        uint32_t v2 = 0;
        if (n2[0] != 0) {
            v2 = strtoul(n2, &tmp, 10);
            if (*tmp != 0) {
                n2 = tmp + 1;
            } else {
                n2 = tmp;
            }
        }

        if (v1 > v2) {
            return 1;
        } else if (v1 < v2) {
            return -1;
        }

        if (n1[0] == 0 && n2[0] == 0) {
            break;
        }
    }

    return 0;
}

int main(int argc, char *argv[])
{
    Solution s;
    cout << s.compareVersion("1.0", "1.0") << endl;
    cout << s.compareVersion("2.0", "1.0") << endl;
    cout << s.compareVersion("1.0.1", "1") << endl;
    cout << s.compareVersion(
                "19.8.3.17.5.01.0.0.4.0.0.0.0.0.0.0.0.0.0.0.0.0.00.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0."
                "0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0."
                "0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.000000.0.0."
                "0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.000000",
                "19.8.3.17.5.01.0.0.4.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0."
                "0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0."
                "0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0000.0.0.0.0.0."
                "0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.000000")
         << endl;
    return 0;
}
