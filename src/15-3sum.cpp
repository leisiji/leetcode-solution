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

    int i = 0, j, k;
    const int n = nums.size();
    int sum = 0;

    for (int i = 0; i < n;) {
        j = i + 1;
        k = n - 1;

        while (j < k) {
            sum = nums[i] + nums[j] + nums[k];
            if (sum == 0) {
                res.push_back({nums[i], nums[j], nums[k]});
                int nums_j = nums[j++];
                while (j < n) {
                    if (nums[j] != nums_j) {
                        break;
                    }
                    j++;
                }
                int nums_k = nums[k--];
                while (k >= 0) {
                    if (nums[k] != nums_k) {
                        break;
                    }
                    k--;
                }
            } else if (sum > 0) {
                k--;
            } else {
                j++;
            }
        }

        int nums_i = nums[i++];
        while (i < n) {
            if (nums[i] != nums_i) {
                break;
            }
            i++;
        }
    }

    return res;
}

void test(vector<int> &a)
{
    Solution s;
    auto res = s.threeSum(a);
    for (auto& i : res) {
        cout << "[";
        for (auto j : i) {
            cout << j << ",";
        }
        cout << "]";
    }
    cout << endl;
}

int main(int argc, char* argv[])
{
    vector<int> a = {-1, 0, 1, 2, -1, -4}; // [[-1,-1,2],[-1,0,1]]
    vector<int> b = {-2, 0, -4, -3, 4, 1, 2, -1, -4};
    test(a);
    test(b);
    return 0;
}
