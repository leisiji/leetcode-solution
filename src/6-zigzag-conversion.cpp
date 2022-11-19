#include <cstdio>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows);
};

/* 核心就是明白 z 字形就是 row++ 到最大后 row--，之后再 row++ */
string Solution::convert(string s, int numRows)
{
    vector<string> arr;
    bool dec = false;
    uint32_t row = 0;

    if (numRows <= 1) {
        return s;
    }

    arr.resize(numRows);

    for (int i = 0; i < s.size(); i++) {
        arr[row].push_back(s.at(i));
        if (row == (numRows - 1)) {
            dec = true;
        } else if (row == 0) {
            dec = false;
        }
        row += dec ? -1 : 1;
    }

    string res;

    for (auto &i : arr) {
        res.append(i);
    }

    return res;
}

int main (int argc, char *argv[])
{
    Solution s;
    cout << s.convert("PAYPALISHIRING", 3) << endl;
    // cout << s.convert("PAYPALISHIRING", 4) << endl;
    return 0;
}
