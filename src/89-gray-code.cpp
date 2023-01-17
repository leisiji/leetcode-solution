#include <cmath>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> grayCode(int n);
};

/* 通过观察可以知道最后一个数应该是 pow(2, n - 1) */
vector<int> Solution::grayCode(int n)
{
    vector<int> out;

    out.reserve(1 << n);
    out.push_back(0);

    for (int i = 1; i <= n; i++) {
        int m = out.size();
        for (int j = m - 1; j >= 0; j--) {
            out.push_back(out[j] | (1 << (i - 1)));
        }
    }

    return out;
}
