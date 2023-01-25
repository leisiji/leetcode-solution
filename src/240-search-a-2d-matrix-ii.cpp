#include <vector>

using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target);
    bool searchMatrix1(vector<vector<int>>& matrix, int target);
};

/* 时间复杂度是 O(m * log(n)) */
bool Solution::searchMatrix(vector<vector<int>>& matrix, int target)
{
    const int m = matrix.size(), n = matrix[0].size();

    for (int col = 0; col < m; col++) {
        if (matrix[col][0] > target) {
            return false;
        }

        if (matrix[col][n - 1] < target) {
            continue;
        }

        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int tmp = matrix[col][mid];
            if (tmp < target) {
                low = mid + 1;
            } else if (tmp > target) {
                high = mid - 1;
            } else {
                return true;
            }
        }
    }

    return false;
}

/* 从右上角开始搜索，比 target 小往左，比 target 大往下：时间复杂度是 O(m+n) */
bool Solution::searchMatrix1(vector<vector<int>>& matrix, int target)
{
    const int m = matrix.size(), n = matrix[0].size();
    int row = 0, col = n - 1;

    while (row < m && col >= 0) {
        auto tmp = matrix[row][col];
        if (tmp < target) {
            row++;
        } else if (tmp > target) {
            col--;
        } else {
            return true;
        }
    }


    return false;
}
