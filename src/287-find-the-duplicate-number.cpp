#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums);
};

int Solution::findDuplicate(vector<int> &nums)
{
    const int len = nums.size();

    for (int i = 0; i < len;) {
        auto tmp = nums[i];
        auto index = tmp - 1;
        if (index == i) {
            i++;
            continue;
        } else if (tmp == nums[index]) {
            return tmp;
        } else {
            swap(nums[index], nums[i]);
        }
    }

    return 0;
}

int main (int argc, char *argv[])
{
    vector<int> a = {1,3,4,2,2};
    Solution s;
    cout << s.findDuplicate(a) << endl;
    return 0;
}
