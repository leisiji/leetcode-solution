#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    void dfs();

public:
    int minimumTotal(vector<vector<int>> &triangle);
};

int Solution::minimumTotal(vector<vector<int>> &triangle)
{
    int ans = INT32_MAX;
    vector<vector<int>> dp;
    const int height = triangle.size();

    dp.emplace_back(vector<int>{triangle[0][0]});

    for (int i = 1; i < height; i++) {
        const int width = triangle[i].size();
        dp.emplace_back(vector<int>(width, 0));

        dp[i][0] = triangle[i][0] + dp[i - 1][0];
        for (int j = 1; j < width - 1; j++) {
            dp[i][j] = std::min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
        }
        dp[i][width - 1] = dp[i - 1][width - 2] + triangle[i][width - 1];
    }

    for (auto &i : dp[height - 1]) {
        ans = std::min(i, ans);
    }

    return ans;
}

int main(int argc, char *argv[])
{
    vector<vector<int>> a = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    Solution s;
    cout << s.minimumTotal(a) << endl;
    return 0;
}
