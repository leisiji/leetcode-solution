#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums);
};

int Solution::missingNumber(vector<int> &nums)
{
    int sum = std::accumulate(nums.begin(), nums.end(), 0);
    const int n = nums.size();
    return (n + 1) * n / 2 - sum;
}
