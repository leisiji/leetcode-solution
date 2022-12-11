#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    int removeElement(vector<int> &nums, int val);
};

int Solution::removeElement(vector<int> &nums, int val)
{
    const int len = nums.size();
    int tail = 0;

    for (int i = 0; i < len; i++) {
        if (nums[i] != val) {
            nums[tail] = nums[i];
            tail++;
        }
    }

    return tail;
}

int main(int argc, char *argv[])
{
    Solution s;
    vector<int> vec {1, 2, 2, 2, 3};
    cout << s.removeElement(vec, 2) << endl;
    for (auto &i : vec) {
        cout << i << ",";
    }
    cout << endl;
    vector<int> vec2 {2, 2, 2};
    cout << s.removeElement(vec2, 2) << endl;
    for (auto &i : vec2) {
        cout << i << ",";
    }
    cout << endl;
    return 0;
}
