#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums);
};

// 移除排好序的重复数组元素
int Solution::removeDuplicates(vector<int> &nums)
{
    int tail = 1;
    int prev = nums[0];
    const int len = nums.size();

    for (int i = 1; i < len; i++) {
        if (prev == nums[i]) {
            continue;
        }
        nums[tail] = nums[i];
        prev = nums[i];
        tail++;
    }

    return tail;
}

void test(vector<int> &arr)
{
    Solution s;

    auto len = s.removeDuplicates(arr);

    for (int i = 0; i < len; i++) {
        cout << arr[i] << ",";
    }
    cout << endl;
}

int main(int argc, char *argv[])
{
    vector<int> a = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    test(a);
    vector<int> b = {0, 0, 0, 0, 1, 1, 1, 2, 2, 2, 3, 3, 4};
    test(b);
    vector<int> c = {1, 2, 3, 4};
    test(c);
    return 0;
}
