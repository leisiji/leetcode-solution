#include <algorithm>
#include <cmath>
#include <iostream>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int>& nums);
};

int Solution::longestConsecutive(vector<int>& nums)
{
    int ret = 0;
    unordered_set<int> set;
    int ans = 0;

    // 去重
    for (auto& i : nums) {
        set.insert(i);
    }

    // 暴力匹配所有数字，连续查找是否存在下一个数，但是加入剪枝手段
    for (auto &i : set) {
        // 只从第一个数开始找，即 x, x+1,... x+y，第一个数前面一个数 x-1 不可能存在于数组
        if (set.find(i - 1) == set.end()) {
            int idx = i + 1;
            while (set.find(idx) != set.end()) {
                idx++;
            }
            ans = std::max(ans, idx - i);
        }
    }

    return ans;
}

int main(int argc, char* argv[])
{
    vector<int> a = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    vector<int> b = {0, 1, 2};
    Solution s;
    cout << s.longestConsecutive(a) << endl;
    cout << s.longestConsecutive(b) << endl;
    return 0;
}
