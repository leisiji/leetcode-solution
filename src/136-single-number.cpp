#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums);
};

int Solution::singleNumber(vector<int> &nums)
{
    int res = nums[0], len = nums.size();

    for (int i = 1; i < len; i++) {
        res = res ^ nums[i];
    }

    return res;
}

int main(int argc, char *argv[])
{
    vector<int> a = {4, 1, 2, 1, 2};
    Solution s;
    cout << s.singleNumber(a) << endl;
    return 0;
}
