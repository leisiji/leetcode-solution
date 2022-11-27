#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs);
};

string Solution::longestCommonPrefix(vector<string> &strs)
{
    string res;
    int min = strs[0].length();
    char s;
    int j = 0;

    for (auto &str : strs) {
        if (str.length() < min) {
            min = str.length();
        }
    }

    for (int i = 0; i < min; i++) {
        s = strs[0].at(i);
        j = 1;
        for (; j < strs.size(); j++) {
            if (s != strs[j].at(i)) {
                break;
            }
        }
        if (j == strs.size()) {
            res.push_back(s);
        } else {
            break;
        }
    }

    return res;
}

int main(int argc, char *argv[])
{
    Solution s;
    vector<string> a = {"flower", "flow", "flight"};
    cout << s.longestCommonPrefix(a) << endl;
    return 0;
}
