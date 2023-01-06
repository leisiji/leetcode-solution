#include <string.h>

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval);
};

vector<vector<int>> Solution::insert(vector<vector<int>>& intervals, vector<int>& newInterval)
{
    vector<vector<int>> out;

    if (intervals.size() == 0) {
        out.push_back(newInterval);
        return out;
    }

    const int len = intervals.size();
    int i = 0;

    while (i < len && intervals[i][1] < newInterval[0]) {
        out.push_back(intervals[i]);
        i++;
    }

    int j = i;
    while (j < len && intervals[j][0] <= newInterval[1]) {
        j++;
    }
    int right = newInterval[1];
    if (j - 1 >= 0) {
        right = max(newInterval[1], intervals[j - 1][1]);
    }
    int left = newInterval[0];
    if (i < len) {
        left = min(newInterval[0], intervals[i][0]);
    }
    out.push_back({left, right});

    while (j < len) {
        out.push_back(intervals[j]);
        j++;
    }

    return out;
}

static void test(vector<vector<int>>& intervals, vector<int>& newInterval)
{
    Solution s;
    auto ret = s.insert(intervals, newInterval);
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
    vector<vector<int>> a = {{1, 3}, {6, 9}};
    vector<int> b = {2, 5};
    test(a, b);

    vector<vector<int>> c = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
    vector<int> d = {4, 8};
    test(c, d);

    vector<vector<int>> e = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
    vector<int> f = {11, 20};
    test(e, f);

    vector<vector<int>> g = {{1,5}};
    vector<int> h = {2,3};
    test(g, h);

    vector<vector<int>> x = {{1,5}};
    vector<int> y = {6,9};
    test(x, y);

    vector<vector<int>> vnull;
    test(vnull, h);

    return 0;
}
