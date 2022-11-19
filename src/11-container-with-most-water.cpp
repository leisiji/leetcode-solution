#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height);
};

/* 双指针，将两个指针分别指向头和尾，核心就是短的那个指针向中心靠 */
int Solution::maxArea(vector<int> &height)
{
    int l = 0, r = height.size() - 1;
    int max = 0;

    while (l < r) {
        if (height[l] < height[r]) {
            max = std::max((r - l) * height[l], max);
            l++;
        } else {
            max = std::max((r - l) * height[r], max);
            r--;
        }
    }

    return max;
}

int main(int argc, char *argv[])
{
    vector<int> a = {1, 8, 6, 2, 5, 4, 8, 3, 7, 3};
    Solution s;
    std::cout << s.maxArea(a) << std::endl;
    return 0;
}
