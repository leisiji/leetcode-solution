#include <vector>

#include "listnode.hpp"

using namespace std;

class Solution
{
private:
    static const char mark_ = '1';
    vector<vector<bool>> visited_;
    vector<vector<char>>* board_;
    int m_, n_;
    void dfs(int m, int n);

public:
    void solve(vector<vector<char>>& board);
};

void Solution::dfs(int m, int n)
{
    if (m == m_ || n == n_ || m < 0 || n < 0 || visited_[m][n]) {
        return;
    }

    auto& cur = board_->at(m)[n];
    visited_[m][n] = true;
    if (cur == 'X') {
        return;
    }

    cur = mark_;
    dfs(m + 1, n);
    dfs(m, n + 1);
    dfs(m - 1, n);
    dfs(m, n - 1);
}

// 遍历 4 个边界，通过 dfs 找到和边界连同的节点
void Solution::solve(vector<vector<char>>& board)
{
    board_ = &board;
    m_ = board.size();
    n_ = board[0].size();

    for (int i = 0; i < m_; i++) {
        visited_.emplace_back(vector<bool>(n_, false));
    }

    for (int i = 0; i < n_; i++) {
        dfs(0, i);
    }
    for (int i = 1; i < m_; i++) {
        dfs(i, 0);
    }
    for (int i = 1; i < m_; i++) {
        dfs(i, n_ - 1);
    }
    for (int i = 1; i < n_ - 1; i++) {
        dfs(m_ - 1, i);
    }

    for (auto &i : board) {
        for (auto &j : i) {
            if (j == mark_) {
                j = 'O';
            } else if (j == 'O') {
                j = 'X';
            }
        }
    }
}

int main(int argc, char* argv[])
{
    vector<vector<char>> board = {
        {'X', 'X', 'X', 'X'}, {'X', 'O', 'O', 'X'}, {'X', 'X', 'O', 'X'}, {'X', 'O', 'X', 'X'}};
    vector<vector<char>> board1 = {{'X', 'O', 'X', 'O', 'X', 'O'},
                                   {'O', 'X', 'O', 'X', 'O', 'X'},
                                   {'X', 'O', 'X', 'O', 'X', 'O'},
                                   {'O', 'X', 'O', 'X', 'O', 'X'}};
    Solution s;
    s.solve(board);
    s.solve(board1);
    print_vec_vec(board);
    print_vec_vec(board1);
    return 0;
}
