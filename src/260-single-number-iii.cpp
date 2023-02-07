#include <vector>

#include "listnode.hpp"
using namespace std;

class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums);
};

vector<int> Solution::singleNumber(vector<int> &nums)
{
    int sum = nums[0];
    const int len = nums.size();
    int mask = 0;
    int a = 0, b = 0;

    for (int i = 1; i < len; i++) {
        sum = sum ^ nums[i];
    }

    for (int i = 0; i < 32; i++) {
        if ((sum & (1 << i)) != 0) {
            mask = 1 << i;
            break;
        }
    }

    for (int i = 0; i < len; i++) {
        auto tmp = nums[i];
        if ((mask & tmp) == 0) {
            a = a ^ tmp;
        } else {
            b = b ^ tmp;
        }
    }

    return {a, b};
}

int main(int argc, char *argv[])
{
    vector<int> a = {1, 2, 1, 3, 2, 5};
    Solution s;
    print_vec(s.singleNumber(a));
    return 0;
}
