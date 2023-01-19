#include <iostream>
#include <string>
#include <vector>

#include "listnode.hpp"

using namespace std;

class Solution
{
private:
    int n_;
    vector<vector<string>> *out_;
    vector<string> tmp_;
    bool valid(int row, int col);
    void backtracking(int row);

public:
    vector<vector<string>> solveNQueens(int n);
};

bool Solution::valid(int row, int col)
{
    // 检查列
    for (int i = 0; i < n_; i++) {
        if (tmp_[i][col] == 'Q') {
            return false;
        }
    }

    // 检查 45 度是否有皇后
    int i = row - 1, j = col - 1;
    while (i >= 0 && j >= 0) {
        if (tmp_[i][j] == 'Q') {
            return false;
        }
        i--, j--;
    }
    i = row + 1, j = col + 1;
    while (i < n_ && j < n_) {
        if (tmp_[i][j] == 'Q') {
            return false;
        }
        i++, j++;
    }

    // 检查 135 度是否有皇后
    i = row - 1, j = col + 1;
    while (i >= 0 && j < n_) {
        if (tmp_[i][j] == 'Q') {
            return false;
        }
        i--, j++;
    }
    i = row + 1, j = col - 1;
    while (i < n_ && j > 0) {
        if (tmp_[i][j] == 'Q') {
            return false;
        }
        i++, j--;
    }

    return true;
}

void Solution::backtracking(int row)
{
    if (row == n_) {
        out_->push_back(tmp_);
        return;
    }

    for (int col = 0; col < n_; col++) {
        if (valid(row, col)) {
            tmp_[row][col] = 'Q';
            backtracking(row + 1);
            tmp_[row][col] = '.';  // 回溯，撤销皇后
        }
    }
}

vector<vector<string>> Solution::solveNQueens(int n)
{
    vector<vector<string>> out;
    out_ = &out;
    n_ = n;
    for (int i = 0; i < n; i++) {
        tmp_.emplace_back(string(n, '.'));
    }

    // N 皇后问题是以行为单位去递归的，因为同一行不可能有 2 个皇后
    backtracking(0);

    return out;
}

int main(int argc, char *argv[])
{
    // [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
    Solution s;
    auto ret = s.solveNQueens(4);
    print_vec_vec(ret);
    return 0;
}
