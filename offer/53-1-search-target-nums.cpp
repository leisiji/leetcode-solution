#include <vector>

using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target);
};

int Solution::search(vector<int> &nums, int target)
{
    int count = 0;

    for (auto &i : nums) {
        if (i == target) {
            count++;
        }
    }

    return count;
}
