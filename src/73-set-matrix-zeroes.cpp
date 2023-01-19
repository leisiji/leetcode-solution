#include <string.h>

#include <vector>

#include "listnode.hpp"

using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix);
};

/* 使用 matrix 的第一行和第一列作为标志位，判断对应的行列是否需要置为 0 */
void Solution::setZeroes(vector<vector<int>> &matrix)
{
    const int m = matrix.size();
    const int n = matrix[0].size();
    bool mzero = false;
    bool nzero = false;

    for (int i = 0; i < m; i++) {
        if (matrix[i][0] == 0) {
            mzero = true;
            break;
        }
    }

    for (int j = 0; j < n; j++) {
        if (matrix[0][j] == 0) {
            nzero = true;
            break;
        }
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    for (int i = 1; i < m; i++) {
        if (matrix[i][0] == 0) {
            memset(matrix[i].data(), 0, sizeof(int) * n);
        }
    }

    for (int j = 1; j < n; j++) {
        if (matrix[0][j] == 0) {
            for (int i = 1; i < m; i++) {
                matrix[i][j] = 0;
            }
        }
    }

    if (nzero) {
        memset(matrix[0].data(), 0, sizeof(int) * n);
    }
    if (mzero) {
        for (int i = 0; i < m; i++) {
            matrix[i][0] = 0;
        }
    }
}

static void test(vector<vector<int>> &a)
{
    Solution s;
    s.setZeroes(a);
    print_vec_vec(a);
}

int main(int argc, char *argv[])
{
    vector<vector<int>> a = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    vector<vector<int>> b = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    vector<vector<int>> c = {{1,0}};
    vector<vector<int>> d = {{1,2,3,4},{5,0,7,8},{0,10,11,12},{13,14,15,0}};
    test(a);
    test(b);
    test(c);
    test(d);
    return 0;
}
