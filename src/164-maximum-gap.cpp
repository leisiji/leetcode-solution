#include <algorithm>
#include <cmath>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

class Solution
{
public:
    int maximumGap(vector<int> &nums);
};

int Solution::maximumGap(vector<int> &nums)
{
    const int len = nums.size();
    if (len < 2) {
        return 0;
    }

    int max = nums[0], min = nums[0];
    for (int i = 1; i < len; i++) {
        max = std::max(nums[i], max);
        min = std::min(nums[i], min);
    }

    // bucket 保存单个桶对应的最大值和最小值
    int d = std::max(1, (max - min) / (len - 1));
    int bucket_size = (max - min) / d + 1;  // 注意这里要 +1
    vector<int[2]> buckets(bucket_size);    // 输入 >= 0
    for (auto &i : buckets) {
        i[0] = i[1] = -1;
    }

    for (auto &num : nums) {
        int index = (num - min) / d;
        auto &tmp = buckets[index];
        if (tmp[0] == -1) {
            tmp[0] = tmp[1] = num;
        } else {
            tmp[0] = std::min(tmp[0], num);
            tmp[1] = std::max(tmp[1], num);
        }
    }

    int ans = 0;
    int prev = -1;
    for (int i = 0; i < bucket_size; i++) {
        if (buckets[i][0] == -1) {
            continue;
        }
        // 注意有数值的桶才需要计算
        if (prev != -1) {
            ans = std::max(ans, buckets[i][0] - buckets[prev][1]);
        }
        prev = i;
    }

    return ans;
}

int main(int argc, char *argv[])
{
    vector<int> a = {15, 6, 3, 9};
    Solution s;
    cout << s.maximumGap(a) << endl;
    return 0;
}
