#include <assert.h>

#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>

using namespace std;

class Solution
{
public:
    string minWindow(string s, string t);
};

string Solution::minWindow(string s, string t)
{
    // 统计 t 中字符出现的次数：两个 int 分别是需要出现的次数，以及当前 window 出现的次数
    unordered_map<char, pair<int, int>> map;

    for (auto &i : t) {
        auto iter = map.find(i);
        if (iter == map.end()) {
            map.insert(make_pair(i, make_pair(1, 0)));
        } else {
            iter->second.first++;
        }
    }

    int left = 0, right = 0;
    const int len = s.size();
    int valid = 0;
    int min = s.size();
    int minl = -1, minr = -1;

    while (right < len) {
        auto iter = map.find(s[right]);
        if (iter != map.end()) {
            iter->second.second++;
            if (iter->second.second == iter->second.first) {
                valid++;
            }
        }

        while (valid == map.size()) {
            auto tmp = right - left;
            if (tmp < min) {
                min = tmp, minl = left, minr = right;
            }
            iter = map.find(s[left++]);
            if (iter != map.end()) {
                if (iter->second.second == iter->second.first) {
                    valid--;
                }
                iter->second.second--;
            }
        }

        right++;
    }

    if (minl == -1) {
        return "";
    }

    return s.substr(minl, minr - minl + 1);
}

int main(int argc, char *argv[])
{
    Solution s;
    cout << s.minWindow("ADOBECODEBANC", "ABC") << endl;  // BANC
    cout << s.minWindow("a", "aa") << endl;               // BANC
    cout << s.minWindow("aa", "aa") << endl;              // BANC
    return 0;
}
