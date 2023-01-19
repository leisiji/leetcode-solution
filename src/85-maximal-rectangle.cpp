#include <iostream>
#include <vector>

#include "listnode.hpp"

using namespace std;

class Solution
{
public:
    int maximalRectangle(vector<vector<char>>& matrix);
};

/* 通过统计每列的 1 连续数量，可以转化为柱形围成的最大矩形（leetcode 84），
 * 以行单位去找最大矩形 */
int Solution::maximalRectangle(vector<vector<char>>& matrix)
{
    int ans = 0;
    const int m = matrix.size(), n = matrix[0].size();
    const int col = n + 2;
    vector<vector<int>> heights(m, vector<int>(col, 0));

    for (int i = 1; i < n + 1; i++) {
        heights[0][i] = matrix[0][i - 1] - '0';
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n + 1; j++) {
            int tmp = matrix[i][j - 1] - '0';
            if (heights[i - 1][j] == 0) {
                heights[i][j] = tmp;
            } else if (tmp == 1) {
                heights[i][j] = heights[i - 1][j] + 1;
            }
        }
    }

    vector<int> mono_st;  // 单调递增的栈
    mono_st.push_back(0);

    // 遍历 heights 数组
    for (int i = 0; i < m; i++) {
        for (int j = 1; j < col; j++) {
            while (heights[i][mono_st.back()] > heights[i][j]) {
                int hcur = heights[i][mono_st.back()];
                mono_st.pop_back();
                int wcur = j - 1 - mono_st.back();
                ans = max(ans, hcur * wcur);
            }
            mono_st.push_back(j);
        }
        mono_st.clear();
        mono_st.push_back(0);
    }

    return ans;
}

int main(int argc, char* argv[])
{
    vector<vector<char>> a = {{'1', '0', '1', '0', '0'},
                              {'1', '0', '1', '1', '1'},
                              {'1', '1', '1', '1', '1'},
                              {'1', '0', '0', '1', '0'}};
    Solution s;
    cout << s.maximalRectangle(a) << endl;  // 6
    return 0;
}
