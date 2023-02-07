#include <vector>

#include "listnode.hpp"

using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums);
};

int Solution::singleNumber(vector<int> &nums)
{
    int ret = 0;

    for (int i = 0; i < 32; i++) {
        int cnt = 0;

        for (auto &num : nums) {
            if ((num & (1 << i)) != 0) {
                cnt++;
            }
        }

        if (cnt % 3 != 0) {
            ret |= 1 << i;
        }
    }

    return ret;
}

int main(int argc, char *argv[])
{
    vector<int> a = {0, 1, 0, 1, 0, 1, 99};
    Solution s;
    cout << s.singleNumber(a) << endl;
    return 0;
}
