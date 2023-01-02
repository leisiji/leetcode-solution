#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix);
};

vector<int> Solution::spiralOrder(vector<vector<int>>& matrix)
{
    int w = matrix[0].size(), h = matrix.size() - 1, x = 0, y = 0;
    bool winc = true, hinc = true;
    const int size = w * matrix.size();
    int i = 0;
    vector<int> out;

    while (i < size) {
        int j = 0;
        while (true) {
            out.push_back(matrix[y][x]);
            j++;
            i++;
            if (j >= w) {
                winc = !winc;
                w--;
                y += (hinc ? 1 : -1);
                break;
            }
            x += (winc ? +1 : -1);
        }

        if (i >= size) {
            break;
        }

        int k = 0;
        while (true) {
            out.push_back(matrix[y][x]);
            k++;
            i++;
            if (k >= h) {
                hinc = !hinc;
                h--;
                x += (winc ? 1 : -1);
                break;
            }
            y += (hinc ? +1 : -1);
        }
    }

    return out;
}

static void test(vector<vector<int>> &a)
{
    Solution s;
    auto ret = s.spiralOrder(a);
    for (auto &i : ret) {
        cout << i << ",";
    }
    cout << endl;
}

int main(int argc, char *argv[])
{
    vector<vector<int>> a = {{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>> b = {{1,2,3}};
    vector<vector<int>> c = {{1,2,3},{4,5,6}};
    test(a);
    test(b);
    test(c);
    return 0;
}
