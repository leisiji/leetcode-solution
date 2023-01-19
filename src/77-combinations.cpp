#include <string.h>

#include <vector>

#include "listnode.hpp"

using namespace std;

class Solution
{
private:
    int n_;
    int k_;
    vector<int> tmp_;
    vector<vector<int>> *out_;
    void backtracking(int k);

public:
    vector<vector<int>> combine(int n, int k);
};

void Solution::backtracking(int index)
{
    if (k_ == tmp_.size()) {
        out_->push_back(tmp_);
    }

    for (int i = index; i < n_; i++) {
        tmp_.push_back(i + 1);
        backtracking(i + 1);
        tmp_.pop_back();
    }
}

vector<vector<int>> Solution::combine(int n, int k)
{
    vector<vector<int>> out;
    tmp_.clear();
    out_ = &out;
    n_ = n;
    k_ = k;
    backtracking(0);
    return out;
}

int main(int argc, char *argv[])
{
    Solution s;
    auto ret = s.combine(4, 2);
    print_vec_vec(ret);
    return 0;
}
