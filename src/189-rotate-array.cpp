#include <vector>
#include <numeric>

#include "listnode.hpp"

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k);
};

static int greatestCommonMeasure(int a, int b)
{
    int r = a % b;
    while (r != 0) {
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

/* 这题本质是找规律，最终发现循环是一个个替换，替换到原来位置即可，而循环的次数是 n 和
 * k 的最大公约数 */
void Solution::rotate(vector<int> &nums, int k)
{
    int n = nums.size();
    int r = k % n;
    if (r == 0) {
        return;
    }
    int loop = std::gcd(n, k);

    for (int j = 0; j < loop; j++) {
        int start = r + j;
        int i = start;
        int prev = nums[i];
        do {
            i = (i + r) % n;
            swap(prev, nums[i]);
        } while (i != start);
    }
}

static void test(vector<int> &a, int k)
{
    Solution s;
    s.rotate(a, k);
    print_vec(a);
}

int main(int argc, char *argv[])
{
    vector<int> a = {1,2,3,4,5,6,7};
    test(a, 3);
    vector<int> b = {1};
    test(b, 3);
    vector<int> c = {-1,-100,3,99};
    test(c, 2);
    vector<int> d = {-1,-100,3,99,5,6};
    test(d, 2);
    vector<int> e = {-1,-100,3,99,5,6};
    test(e, e.size());
    vector<int> g = {1,2,3,4,5,6};
    test(g, 4);
    return 0;
}
