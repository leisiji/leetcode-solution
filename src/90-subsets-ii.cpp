#include <iterator>
#include <unordered_map>
#include <utility>
#include <vector>

#include "listnode.hpp"

using namespace std;

class Solution
{
private:
    unordered_map<int, int> map_;
    vector<int> tmp_;
    vector<vector<int>> *out_;
    void backtracking(decltype(map_)::iterator iter);

public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums);
};

/* 重点在于如何去重 */
void Solution::backtracking(decltype(map_)::iterator start)
{
    if (start == map_.end()) {
        out_->push_back(tmp_);
        return;
    }

    auto len = start->second, value = start->first;
    for (int i = 0; i <= len; i++) {
        for (int j = 0; j < i; j++) {
            tmp_.push_back(value);
        }
        backtracking(next(start));
        tmp_.resize(tmp_.size() - i);
    }
}

vector<vector<int>> Solution::subsetsWithDup(vector<int> &nums)
{
    vector<vector<int>> out;
    out_ = &out;
    map_.clear();
    tmp_.clear();

    for (auto &i : nums) {
        auto iter = map_.find(i);
        if (iter != map_.end()) {
            iter->second = iter->second + 1;
        } else {
            map_.insert(make_pair(i, 1));
        }
    }

    backtracking(map_.begin());

    return out;
}

int main(int argc, char *argv[])
{
    vector<int> a = {1, 2, 2};
    Solution s;
    auto ret = s.subsetsWithDup(a);
    print_vec_vec(ret);
    return 0;
}
