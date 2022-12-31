#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums);
};

/* 通过 nums[i] < nums[i + 1] 找到 peek；该题只能使用开区间写法 */
int Solution::findPeakElement(vector<int> &nums)
{
    int low = -1, high = nums.size() - 1, mid;

    while (low + 1 < high) {
        mid = (low + high) >> 1;
        if (nums[mid] < nums[mid+1]) {
            low = mid;
        } else {
            high = mid;
        }
    }

    return high;
}

int main(int argc, char *argv[])
{
    vector<int> a = {1,2,3,1};
    Solution s;
    cout << s.findPeakElement(a) << endl;

    vector<int> b = {1,2,3};
    cout << s.findPeakElement(b) << endl;
    return 0;
}
