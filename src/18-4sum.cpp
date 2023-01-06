#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target);
};

// 还可以进行剪枝处理
vector<vector<int>> Solution::fourSum(vector<int>& nums, int target)
{
    const int len = nums.size();
    vector<vector<int>> out;

    if (len < 4) {
        return out;
    }

    int a, b, c, d;
    int64_t sum;

    sort(nums.begin(), nums.end());

    for (a = 0; a < len - 3;) {
        for (b = a + 1; b < len - 2;) {
            c = b + 1;
            d = len - 1;

            while (c < d) {
                int nums_c = nums[c], nums_d = nums[d];
                sum = (int64_t)nums[a] + nums[b] + nums_c + nums_d;
                if (sum == target) {
                    out.push_back({nums[a], nums[b], nums_c, nums_d});

                    do {
                        c++;
                    } while (c < len && nums[c] == nums_c);
                    do {
                        d--;
                    } while (d > 0 && nums[d] == nums_d);

                } else if (sum < target) {
                    c++;
                } else {
                    d--;
                }
                // cout << "a: " << a << ", b: " << b << ",c: " << c << ", d: " << d << endl;
            }

            int nums_b = nums[b];
            do {
                b++;
            } while (b < len && nums[b] == nums_b);
        }

        int nums_a = nums[a];
        do {
            a++;
        } while (a < len && nums[a] == nums_a);
    }

OUT:
    return out;
}

static void test(vector<int>& arr, int target)
{
    Solution s;
    auto ret = s.fourSum(arr, target);
    for (auto& i : ret) {
        cout << "[";
        for (auto& j : i) {
            cout << j << ",";
        }
        cout << "],";
    }
    cout << endl;
}

int main(int argc, char* argv[])
{
    vector<int> a = {1, 0, -1, 0, -2, 2};
    test(a, 0);
    vector<int> b = {2, 2, 2, 2, 2};
    test(b, 8);
    return 0;
}
