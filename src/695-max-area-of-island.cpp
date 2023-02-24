#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    int m_, n_;
    vector<vector<bool>> visited_;
    vector<vector<int>> *grid_;
    void dfs(int m, int n);
    int area_;

public:
    int maxAreaOfIsland(vector<vector<int>> &grid);
};

void Solution::dfs(int m, int n)
{
    if (m == m_ || n == n_ || m < 0 || n < 0 || visited_[m][n]) {
        return;
    }

    auto &tmp = grid_->at(m).at(n);
    visited_[m][n] = true;
    if (tmp == 1) {
        area_++;
        dfs(m + 1, n);
        dfs(m, n + 1);
        dfs(m - 1, n);
        dfs(m, n - 1);
    }
}

int Solution::maxAreaOfIsland(vector<vector<int>> &grid)
{
    int ans = 0;
    m_ = grid.size(), n_ = grid[0].size();
    vector<vector<bool>> visited(m_, vector<bool>(n_, false));
    grid_ = &grid;
    visited_ = std::move(visited);

    for (int i = 0; i < m_; i++) {
        for (int j = 0; j < n_; j++) {
            area_ = 0;
            dfs(i, j);
            ans = max(ans, area_);
        }
    }

    return ans;
}

int main(int argc, char *argv[])
{
    vector<vector<int>> grid = {
        {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
        {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
        {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};
    Solution s;
    cout << s.maxAreaOfIsland(grid) << endl;
    return 0;
}
