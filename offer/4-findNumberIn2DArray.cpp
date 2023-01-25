#include <vector>

using namespace std;

class Solution
{
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target);
};

// 在一个 m * n
// 的二维数组中，每一行都按照从左到右"非递减"的顺序排序，每一列都按照从上到下"非递减"的顺序排序
bool Solution::findNumberIn2DArray(vector<vector<int>>& matrix, int target)
{
    const int m = matrix.size();
    if (m == 0) {
        return false;
    }

    const int n = matrix[0].size();
    if (n == 0) {
        return false;
    }

    for (int col = 0; col < m; col++) {
        int low = 0, high = n - 1;

        if (matrix[col][0] > target) {
            return false;
        }

        while (low <= high) {
            auto mid = (low + high) >> 1;
            auto tmp = matrix[col][mid];
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

int main (int argc, char *argv[])
{
    vector<vector<int>> a = {{}};
    Solution s;
    s.findNumberIn2DArray(a, 1);
    return 0;
}
