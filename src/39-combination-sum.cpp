#include <algorithm>
#include <vector>
#include "listnode.hpp"

using namespace std;

class Solution
{
private:
    vector<vector<int>> *out_;
    vector<int> tmp_;
    vector<int> *candidates_;
    int target_;
    void combinationSum(int sum, int index);
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target);
};

void Solution::combinationSum(int sum, int index)
{
    if (sum == target_) {
        out_->push_back(tmp_);
        return;
    } else if (sum > target_) {
        return;
    }

    const int len = candidates_->size();
    for (int i = index; i < len; i++) {
        int tmp = candidates_->at(i);
        tmp_.push_back(tmp);
        combinationSum(sum + tmp, i); // 由于数字可以重复使用，这里传入原值就可以
        tmp_.pop_back();
    }
}

vector<vector<int>> Solution::combinationSum(vector<int>& candidates, int target)
{
    vector<vector<int>> out;
    out_ = &out;
    target_ = target;
    candidates_ = &candidates;
    combinationSum(0, 0);
    return out;
}

int main(int argc, char *argv[])
{
    vector<int> a = {2,3,6,7};
    Solution s;
    auto ret = s.combinationSum(a, 7);
    print_vec_vec(ret);
    return 0;
}
