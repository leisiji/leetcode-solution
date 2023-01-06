#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals);
};

vector<vector<int>> Solution::merge(vector<vector<int>>& intervals)
{
    vector<vector<int>> out;

    sort(intervals.begin(), intervals.end());

    out.push_back(intervals[0]);

    for (int i = 1; i < intervals.size(); i++) {
        auto &last = out.back();
        if (last[1] < intervals[i][0]) {
            out.push_back(intervals[i]);
        } else {
            last[1] = max(intervals[i][1], last[1]);
        }
    }

    return out;
}

static void test(vector<vector<int>>& a)
{
    Solution s;
    auto ret = s.merge(a);
    for (auto& i : ret) {
        cout << "[";
        for (auto& j : i) {
            cout << j << ",";
        }
        cout << "], ";
    }
    cout << endl;
}

int main(int argc, char* argv[])
{
    vector<vector<int>> a = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    test(a);
    vector<vector<int>> b = {{1, 4}, {4, 5}};
    test(b);
    vector<vector<int>> c = {{1, 4}, {1, 4}};
    test(c);
    vector<vector<int>> d = {{4, 5}, {1, 2}};
    test(d);
    vector<vector<int>> e = {{1, 4}, {0, 4}};
    test(e);
    vector<vector<int>> f = {{4, 5}, {1, 4}, {0, 1}};
    test(f);
    return 0;
}
