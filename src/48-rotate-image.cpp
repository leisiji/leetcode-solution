#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix);
};

void Solution::rotate(vector<vector<int>> &matrix)
{
    int times = 0;
    int nums = matrix.size();

    while (times <= (nums >> 1)) {
        int len = nums - (times << 1);
        for (int i = 0; i < len - 1; ++i) {
            int temp = matrix[times][times + i];
            matrix[times][times + i] = matrix[times + len - i - 1][times];
            matrix[times + len - i - 1][times] = matrix[times + len - 1][times + len - i - 1];
            matrix[times + len - 1][times + len - i - 1] = matrix[times + i][times + len - 1];
            matrix[times + i][times + len - 1] = temp;
        }
        ++times;
    }
}

int main(int argc, char *argv[])
{
    vector<vector<int>> a = {{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
    Solution s;
    s.rotate(a);
    cout << "{";
    for (auto &i : a) {
        cout << "[";
        for (auto &j : i) {
            cout << j << ",";
        }
        cout << "],";
    }
    cout << "}" << endl;
    return 0;
}
