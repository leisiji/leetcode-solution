#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    vector<int>* nums_;
    int target_;
    int last_;
    bool low_move_right(int index);

public:
    int search(vector<int>& nums, int target);
};

bool Solution::low_move_right(int index)
{
    int tmp = nums_->at(index);

    if (tmp > last_) {
        if (tmp < target_ || target_ <= last_) {
            return true;
        }
    } else {
        if (tmp < target_ && target_ <= last_) {
            return true;
        }
    }

    return false;
}

int Solution::search(vector<int>& nums, int target)
{
    nums_ = &nums;
    target_ = target;
    last_ = nums[nums.size() - 1];

    int low = -1, high = nums.size();

    while (low + 1 < high) {
        int mid = (low + high) >> 1;

        if (nums[mid] == target) {
            return mid;
        }

        if (low_move_right(mid)) {
            low = mid;
        } else {
            high = mid;
        }
    }

    return -1;
}

int main(int argc, char* argv[])
{
    Solution s;
    vector<int> a = {4, 5, 6, 7, 0, 1, 2};
    vector<int> b = {1};
    vector<int> c = {1, 3};
    cout << s.search(a, 0) << endl;
    cout << s.search(a, 3) << endl;
    cout << s.search(b, 1) << endl;
    cout << s.search(c, 2) << endl;
    cout << s.search(c, 3) << endl;
    return 0;
}
