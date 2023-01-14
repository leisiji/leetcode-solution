#include <assert.h>

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
private:
    vector<vector<char>> *board_;
    int row_, col_;
    string *word_;
    vector<vector<bool>> visitied_;
    bool dfs(int row, int col, int n);

public:
    bool exist(vector<vector<char>> &board, string word);
};

bool Solution::dfs(int row, int col, int n)
{
    if (row == row_ || col == col_ || row < 0 || col < 0 || visitied_[row][col]) {
        return false;
    }

    if (board_->at(row).at(col) != word_->at(n)) {
        return false;
    }

    if (n + 1 == word_->length()) {
        return true;
    }

    visitied_[row][col] = true;
    auto ret = dfs(row + 1, col, n + 1);
    if (ret) {
        return true;
    }
    ret = dfs(row, col + 1, n + 1);
    if (ret) {
        return true;
    }
    ret = dfs(row - 1, col, n + 1);
    if (ret) {
        return true;
    }
    ret = dfs(row, col - 1, n + 1);
    if (ret) {
        return true;
    }
    visitied_[row][col] = false;

    return false;
}

bool Solution::exist(vector<vector<char>> &board, string word)
{
    word_ = &word;
    board_ = &board;
    row_ = board.size();
    col_ = board[0].size();

    for (int i = 0; i < row_; i++) {
        visitied_.push_back(vector<bool>(col_, false));
    }

    for (int i = 0; i < row_; i++) {
        for (int j = 0; j < col_; j++) {
            if (dfs(i, j, 0)) {
                return true;
            }
        }
    }

    return false;
}

int main(int argc, char *argv[])
{
    vector<vector<char>> a = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    Solution s;
    assert(s.exist(a, "ABCCED"));
    return 0;
}
