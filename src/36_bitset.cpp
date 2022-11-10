#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>>& board)
    {
        bool row[9][9] = {{false}};
        bool col[9][9] = {{false}};
        bool region[9][9] = {{false}};
        char s = '.';
        int regionNum = 0;

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                s = board[i][j];

                if (s == '.') {
                    continue;
                }

                regionNum = ((int)(i / 3) * 3) + ((int)(j / 3));
                s = s - 49;

                if (row[i][s] || col[j][s] || region[regionNum][s]) {
                    return false;
                }

                row[i][s] = true;
                col[j][s] = true;
                region[regionNum][s] = true;
            }
        }

        return true;
    }
};

int main(int argc, char* argv[])
{
    vector<vector<char>> v = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                              {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                              {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                              {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                              {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                              {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                              {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                              {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                              {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    Solution s;

    cout << s.isValidSudoku(v) << endl;

    return 0;
}
