#include <vector>

#include "listnode.hpp"

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits);
};

vector<int> Solution::plusOne(vector<int>& digits)
{
    int cur = 1;
    const int len = digits.size();
    vector<int> out(len);

    for (int i = len - 1; i >= 0; i--) {
        if (digits[i] == 9 && cur == 1) {
            out[i] = 0;
        } else {
            out[i] = cur + digits[i];
            cur = 0;
        }
    }

    if (cur == 1) {
        vector<int> ans(digits.size() + 1);
        ans[0] = 1;
        return ans;
    }

    return out;
}

int main (int argc, char *argv[])
{
    Solution s;
    vector<int> a = {1,2,3};
    auto ret = s.plusOne(a);
    print_vec(ret);

    vector<int> b = {9,9};
    ret = s.plusOne(b);
    print_vec(ret);
    return 0;
}
