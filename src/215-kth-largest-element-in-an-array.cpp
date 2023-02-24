#include <vector>

using namespace std;

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k);
};

static int partition(vector<int> &nums, int start, int end)
{
    int mid = (start + end) >> 1;
    int left = start, pivot = nums[mid];

    swap(nums[mid], nums[start]);
    for (int i = left + 1; i <= end; i++) {
        if (nums[i] > pivot) {
            left++;
            swap(nums[left], nums[i]);
        }
    }
    swap(nums[start], nums[left]);

    return left;
}

static void largetest_k(vector<int> &nums, int start, int end, int k)
{
    int p = partition(nums, start, end);
    if (p < k) {
        largetest_k(nums, p + 1, end, k);
    } else if (p > k) {
        largetest_k(nums, start, p - 1, k);
    }
}

int Solution::findKthLargest(vector<int> &nums, int k)
{
    largetest_k(nums, 0, nums.size() - 1, k - 1);
    return nums[k - 1];
}
