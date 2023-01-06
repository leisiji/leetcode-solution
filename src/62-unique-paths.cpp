#include <assert.h>
#include <string.h>

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int uniquePaths(int m, int n);
};

int Solution::uniquePaths(int m, int n)
{
    vector<vector<int>> ans;

    ans.reserve(m);

    for (int i = 0; i < m; i++) {
        vector<int> tmp;
        tmp.reserve(n);
        for (int j = 0; j < n; j++) {
            tmp.push_back(1);
        }
        ans.emplace_back(tmp);
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            ans[i][j] = ans[i - 1][j] + ans[i][j - 1];
        }
    }

    return ans[m - 1][n - 1];
}

int main(int argc, char *argv[])
{
    Solution s;
    assert(s.uniquePaths(3, 7) == 28);
    assert(s.uniquePaths(3, 2) == 3);
    assert(s.uniquePaths(3, 3) == 6);
    assert(s.uniquePaths(1, 1) == 1);
    return 0;
}
