#include <vector>

#include "listnode.h"

using namespace std;

class Solution
{
private:
    int k_;
    int n_;
    void combinationSum(int sum, int index);
    vector<vector<int>> *out_;
    vector<int> tmp_;

public:
    vector<vector<int>> combinationSum3(int k, int n);
};

void Solution::combinationSum(int sum, int index)
{
    if (sum == n_ && tmp_.size() == k_) {
        out_->push_back(tmp_);
        return;
    } else if (sum > n_ || tmp_.size() >= k_) {
        return;
    }

    for (int i = index; i < 9; i++) {
        int tmp = i + 1;
        tmp_.push_back(tmp);
        combinationSum(sum + tmp, i + 1);
        tmp_.pop_back();
    }
}

vector<vector<int>> Solution::combinationSum3(int k, int n)
{
    vector<vector<int>> out;
    k_ = k;
    n_ = n;
    tmp_.clear();
    out_ = &out;
    combinationSum(0, 0);
    return out;
}

int main(int argc, char *argv[])
{
    Solution s;
    auto ret = s.combinationSum3(3, 7);
    print_vec_vec(ret);
    return 0;
}
