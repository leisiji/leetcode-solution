#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums);
};

bool Solution::canJump(vector<int> &nums)
{
    bool jump_zero = false;
    int zero_pos = -1;

    for (int i = nums.size() - 1; i >= 0; i--) {
        if (nums[i] == 0 && jump_zero == true) {
            zero_pos = i;
            jump_zero = false;
        } else {
            int tmp = i + nums[i];
            // cout << i << "," << zero_pos << endl;
            if (tmp > zero_pos) {
                jump_zero = true;
            }
        }
    }

    return jump_zero;
}

int main(int argc, char *argv[])
{
    vector<int> a = {2,3,1,1,4};
    vector<int> b = {3,2,1,0,4};
    vector<int> c = {3,2,1,0,3,2,1,0,4};
    vector<int> d = {4,2,1,0,0,4};
    Solution s;
    // std::cout << s.canJump(a) << std::endl;
    std::cout << s.canJump(b) << std::endl;
    std::cout << s.canJump(c) << std::endl;
    std::cout << s.canJump(d) << std::endl;
    return 0;
}
