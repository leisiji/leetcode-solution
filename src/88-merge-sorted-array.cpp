#include <vector>

#include "listnode.h"

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n);
};

void Solution::merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int end = m + n - 1;
    int i1 = m - 1, i2 = n - 1;

    while (i1 >= 0 && i2 >= 0) {
        int n1 = nums1[i1], n2 = nums2[i2];
        if (n1 < n2) {
            nums1[end] = n2;
            i2--;
        } else {
            nums1[end] = n1;
            i1--;
        }
        end--;
    }

    while (i1 >= 0) {
        nums1[end] = nums1[i1];
        end--, i1--;
    }

    while (i2 >= 0) {
        nums1[end] = nums2[i2];
        end--, i2--;
    }
}

int main (int argc, char *argv[])
{
    vector<int> a = {1,2,3,0,0,0};
    vector<int> b = {2,5,6};
    Solution s;
    // s.merge(a, 3, b, 3);
    print_vec(a);

    vector<int> c = {0};
    vector<int> d = {1};
    s.merge(c, 0, d, 1);
    print_vec(c);

    return 0;
}
