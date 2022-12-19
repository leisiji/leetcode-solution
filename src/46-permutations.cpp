#include <string.h>
#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

class Solution
{
private:
    int len_ = 0;
    vector<int> nums_;
    vector<int> res_;
    vector<int> visited_;
    void permute(vector<vector<int>> &out, int n);

public:
    vector<vector<int>> permute(vector<int> &nums);
};

void Solution::permute(vector<vector<int>> &out, int n)
{
    if (n == len_) {
        out.push_back(res_);
        return;
    }

    for (int i = 0; i < len_; i++) {
        if (visited_[i] == 0) {
            res_.push_back(nums_[i]);
            visited_[i] = 1;
            permute(out, n + 1);
            visited_[i] = 0;
            res_.pop_back();
        }
    }
}

vector<vector<int>> Solution::permute(vector<int> &nums)
{
    vector<vector<int>> res;

    len_ = nums.size();
    nums_ = nums;

    visited_.reserve(len_);
    memset(visited_.data(), 0, len_ * sizeof(int));

    permute(res, 0);

    return res;
}

static void test(vector<int> &nums)
{
    Solution s;

    auto res = s.permute(nums);
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
    vector<int> b = {1};
    test(b);

    vector<int> a = {1,2,3};
    test(a);

    vector<int> c = {1,2,4,5};
    test(c);


    return 0;
}
