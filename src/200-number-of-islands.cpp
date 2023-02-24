#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    int m_, n_;
    vector<vector<bool>> visited_;
    vector<vector<char>> *grid_;
    void dfs(int m, int n);

public:
    int numIslands(vector<vector<char>> &grid);
};

void Solution::dfs(int m, int n)
{
    if (m == m_ || n == n_ || m < 0 || n < 0 || visited_[m][n]) {
        return;
    }

    auto &tmp = grid_->at(m).at(n);
    visited_[m][n] = true;
    if (tmp == '1') {
        dfs(m + 1, n);
        dfs(m, n + 1);
        dfs(m - 1, n);
        dfs(m, n - 1);
    }
}

int Solution::numIslands(vector<vector<char>> &grid)
{
    int num = 0;
    m_ = grid.size(), n_ = grid[0].size();
    vector<vector<bool>> visited(m_, vector<bool>(n_, false));
    grid_ = &grid;
    visited_ = std::move(visited);

    for (int i = 0; i < m_; i++) {
        for (int j = 0; j < n_; j++) {
            if (visited_[i][j] || grid[i][j] == '0') {
                continue;
            }
            num++;
            dfs(i, j);
        }
    }

    return num;
}

int main(int argc, char *argv[])
{
    vector<vector<char>> grid = {{'1', '1', '1', '1', '0'},
                                 {'1', '1', '0', '1', '0'},
                                 {'1', '1', '0', '0', '0'},
                                 {'0', '0', '0', '0', '0'}};
    vector<vector<char>> grid1 = {{'1', '1', '0', '0', '0'},
                                  {'1', '1', '0', '0', '0'},
                                  {'0', '0', '1', '0', '0'},
                                  {'0', '0', '0', '1', '1'}};
    Solution s;
    cout << s.numIslands(grid) << endl;
    cout << s.numIslands(grid1) << endl;
    return 0;
}
