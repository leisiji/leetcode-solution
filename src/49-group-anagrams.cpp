#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs);
};

vector<vector<string>> Solution::groupAnagrams(vector<string>& strs)
{
    unordered_map<string, int> map;
    vector<vector<string>> out;

    for (auto& str : strs) {
        auto tmp = str;
        sort(tmp.begin(), tmp.end());
        auto i = map.find(tmp);
        if (i != map.end()) {
            out[i->second].push_back(str);
        } else {
            out.push_back({str});
            map.insert(make_pair(tmp, out.size() - 1));
        }
    }

    return out;
}

int main(int argc, char* argv[])
{
    vector<string> a = {"eat", "tea", "tan", "ate", "nat", "bat"};
    Solution s;
    auto out = s.groupAnagrams(a);
    for (auto &i : out) {
        cout << "[";
        for (auto &j : i) {
            cout << j << ",";
        }
        cout << "],";
    }
    cout << endl;
    return 0;
}
