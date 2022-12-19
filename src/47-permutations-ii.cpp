#include <algorithm>
#include <cstring>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

class Solution
{
private:
    int len_ = 0;
    vector<int> visited_;
    vector<int> *nums_;
    vector<int> res_;
    void permuteUnique(vector<vector<int>> &out);

public:
    vector<vector<int>> permuteUnique(vector<int> &nums);
};

void Solution::permuteUnique(vector<vector<int>> &out)
{
    if (res_.size() == len_) {
        out.push_back(res_);
        return;
    }

    for (int i = 0; i < len_; i++) {
        int num = nums_->at(i);
        if (visited_[i] == 1) {
            continue;
        }
        // 注意这里 visited_ 是 i - 1
        if ((i > 0 && num == nums_->at(i - 1)) && visited_[i - 1] == 0) {
            continue;
        }

        visited_[i] = 1;
        res_.push_back(num);

        permuteUnique(out);

        visited_[i] = 0;
        res_.pop_back();
    }
}

vector<vector<int>> Solution::permuteUnique(vector<int> &nums)
{
    vector<vector<int>> res;

    len_ = nums.size();
    nums_ = &nums;

    // 重点在于先排序，排序后可以和前一个元素比较，就可以知道是否重复
    sort(nums.begin(), nums.end());

    visited_.reserve(len_);
    memset(visited_.data(), 0, len_ * sizeof(int));

    permuteUnique(res);

    return res;
}
static void test(vector<int> &nums)
{
    Solution s;

    auto res = s.permuteUnique(nums);
    for (auto &i : res) {
        std::cout << "[";
        for (auto &j : i) {
            std::cout << j << ",";
        }
        std::cout << "],";
    }
    std::cout << std::endl;
}

int main(int argc, char *argv[])
{
    vector<int> a = {1, 1, 2};
    test(a);
    return 0;
}
