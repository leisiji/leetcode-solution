#include <vector>

#include "listnode.h"

using namespace std;

class Solution
{
private:
    vector<vector<int>>* out_;
    int n_;
    vector<int> *nums_;
    vector<int> tmp_;
    void dfs(int n);

public:
    vector<vector<int>> subsets(vector<int>& nums);
};

void Solution::dfs(int n)
{
    if (n == n_) {
        out_->push_back(tmp_);
        return;
    }

    tmp_.push_back(nums_->at(n));
    dfs(n + 1);
    tmp_.pop_back();
    dfs(n + 1);
}

// 在子集中，每个数字是出现或不出现这 2 种可能
vector<vector<int>> Solution::subsets(vector<int>& nums)
{
    vector<vector<int>> out;
    out_ = &out;
    n_ = nums.size();
    nums_ = &nums;

    dfs(0);

    return out;
}

int main (int argc, char *argv[])
{
    Solution s;
    vector<int> a = {1,2,3};
    auto ret = s.subsets(a);
    print_vec_vec(ret);
    return 0;
}
