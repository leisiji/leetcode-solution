#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int>& nums);
};

/* 重点在于如何快速去除无用解：
 * 1. 先排序，这个是为了 2
 * 2. 使用 3 个指针 i, j, k；若 nums[i] >= 0，则需要跳出循环
 * 3. 跳过和 i, j, k 重复的元素
 * */
vector<vector<int>> Solution::threeSum(vector<int>& nums)
{
    vector<vector<int>> res;

    sort(nums.begin(), nums.end());

    int i = 0, j = 1, k = 2;

    while (k < nums.size()) {
        if (nums[i] >= 0) {
            break;
        }
    }

    return res;
}

int main(int argc, char* argv[])
{
    Solution s;
    vector<int> a = {-1, 0, 1, 2, -1, -4};
    auto res = s.threeSum(a);
    for (auto& i : res) {
        cout << "[";
        for (auto j : i) {
            cout << j << ",";
        }
        cout << "]";
    }
    cout << endl;
    return 0;
}
