#include <vector>
#include <iostream>
#include "listnode.hpp"

using namespace std;

class Solution
{
public:
    vector<int> getRow(int rowIndex);
};

vector<int> Solution::getRow(int rowIndex)
{
    vector<int> cur(rowIndex + 1, 1);

    for (int i = 2; i <= rowIndex; i++) {
        int prev = 1;
        for (int j = 1; j < i; j++) {
            int sum = prev + cur[j];
            prev = cur[j];
            cur[j] = sum;
        }
    }

    return cur;
}

int main (int argc, char *argv[])
{
    Solution s;
    auto ret = s.getRow(3);
    print_vec(ret);
    return 0;
}
