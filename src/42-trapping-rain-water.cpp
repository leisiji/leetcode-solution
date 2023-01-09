#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int trap(vector<int>& height);
    int trap1(vector<int>& height);
};

int Solution::trap(vector<int>& height)
{
    int ans = 0;
    const int len = height.size();
    int left = 0, right = len - 1;
    int lmax = 0, rmax = 0, tmp;

    while (left <= right) {
        lmax = max(lmax, height[left]);
        rmax = max(rmax, height[right]);
        if (lmax > rmax) {
            ans += rmax - height[right];
            right--;
        } else {
            ans += lmax - height[left];
            left++;
        }
    }

    return ans;
}

int Solution::trap1(vector<int>& height)
{
    int ans = 0;
    const int len = height.size();
    vector<int> left_max(len);
    vector<int> right_max(len);
    int lmax = 0, rmax = 0;

    for (int i = 0; i < len; i++) {
        if (height[i] > lmax) {
            lmax = height[i];
        }
        left_max[i] = lmax;
    }

    for (int i = len - 1; i >= 0; i--) {
        if (height[i] > rmax) {
            rmax = height[i];
        }
        right_max[i] = rmax;
    }

    for (int i = 0; i < len; i++) {
        int tmp = min(left_max[i], right_max[i]) - height[i];
        if (tmp > 0) {
            ans += tmp;
        }
    }

    return ans;
}

int main (int argc, char *argv[])
{
    vector<int> a = {0,1,0,2,1,0,1,3,2,1,2,1};
    Solution s;
    cout << s.trap(a) << endl;
    return 0;
}
