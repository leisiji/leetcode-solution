#include <algorithm>
#include <iostream>
#include <vector>

#include "listnode.hpp"

using namespace std;

class Solution
{
public:
    int maximalSquare(vector<vector<char>>& matrix);
};

// dp[i][j] 表示包含了该点在内的最大正方形
int Solution::maximalSquare(vector<vector<char>>& matrix)
{
    const int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    int ans = 0;

    for (int i = 0; i < m; i++) {
        if (matrix[i][0] == '1') {
            dp[i][0] = 1;
            ans = 1;
        }
    }

    for (int i = 1; i < n; i++) {
        if (matrix[0][i] == '1') {
            dp[0][i] = 1;
            ans = 1;
        }
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (matrix[i][j] == '1') {
                dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
            }
            ans = max(ans, dp[i][j]);
        }
    }

    return ans * ans;
}

int main(int argc, char* argv[])
{
    vector<vector<char>> matrix = {{'1', '0', '1', '0', '0'},
                                   {'1', '0', '1', '1', '1'},
                                   {'1', '1', '1', '1', '1'},
                                   {'1', '0', '0', '1', '0'}};
    vector<vector<char>> matrix1 = {{'1', '1', '1', '1', '0'},
                                    {'1', '1', '1', '1', '0'},
                                    {'1', '1', '1', '1', '1'},
                                    {'1', '1', '1', '1', '1'},
                                    {'0', '0', '1', '1', '1'}};
    Solution s;
    cout << s.maximalSquare(matrix) << endl;
    cout << s.maximalSquare(matrix1) << endl;
    return 0;
}
