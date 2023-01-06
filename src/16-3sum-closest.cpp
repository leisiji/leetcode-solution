#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target);
};

int Solution::threeSumClosest(vector<int> &nums, int target)
{
    int i, j, k, sum = nums[0] + nums[1] + nums[2], ans = sum;
    const int len = nums.size();

    sort(nums.begin(), nums.end());

    for (i = 0; i < len; i++) {
        j = i + 1;
        k = len - 1;

        while (j < k) {
            sum = nums[i] + nums[j] + nums[k];
            int distance = sum - target;
            if (distance < 0) {
                j++;
            } else if (distance > 0) {
                k--;
            } else {
                return target;
            }
            if (abs(sum - target) < abs(ans - target)) {
                ans = sum;
            }
        }
    }

    return ans;
}

int main(int argc, char *argv[])
{
    vector<int> a = {-1, 2, 1, -4};
    Solution s;
    cout << s.threeSumClosest(a, 1) << endl;
    vector<int> b = {0, 0, 0};
    cout << s.threeSumClosest(b, 1) << endl;
    vector<int> c = {0,1,2};
    cout << s.threeSumClosest(c, 3) << endl;
    return 0;
}
