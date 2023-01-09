#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target);
};

bool Solution::searchMatrix(vector<vector<int>> &matrix, int target)
{
    const int m = matrix.size(), n = matrix[0].size();
    int left, right;

    left = 0, right = m - 1;
    while (left <= right) {
        int mid = (left + right) >> 1;
        int tmp = matrix[mid][0];
        if (tmp == target) {
            return true;
        } else if (tmp < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    int s = right;
    if (s == -1) {
        return false;
    }

    left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) >> 1;
        int tmp = matrix[s][mid];
        if (tmp == target) {
            return true;
        } else if (tmp < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return false;
}

int main(int argc, char *argv[])
{
    vector<vector<int>> a = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    vector<vector<int>> b = {{1}};
    Solution s;
    cout << s.searchMatrix(a, 16) << endl;
    cout << s.searchMatrix(b, 0) << endl;
    return 0;
}
