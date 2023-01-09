#include <stdint.h>

#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid);
};

/* 由于只能往下或往右移动，因此可以知道所有路径的长度都是一致的，
 * 因此找一条最小和的路径即可 */
int Solution::minPathSum(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> ans(m, vector<int>(n, 0));

    ans[0][0] = grid[0][0];

    for (int i = 1; i < m; i++) {
        ans[i][0] = ans[i - 1][0] + grid[i][0];
    }

    for (int j = 1; j < n; j++) {
        ans[0][j] = ans[0][j - 1] + grid[0][j];
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            ans[i][j] = std::min(ans[i - 1][j], ans[i][j - 1]) + grid[i][j];
        }
    }

    return ans[m - 1][n - 1];
}

int main(int argc, char *argv[])
{
    return 0;
}
