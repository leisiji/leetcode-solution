#include <iostream>
#include <vector>

using namespace std;

static void swap(vector<int>& nums, int index1, int index2)
{
    int temp = nums[index1];
    nums[index1] = nums[index2];
    nums[index2] = temp;
}

static int partition(vector<int>& nums, int left, int right)
{
    int index = (right - left + 1) / 2 + left;
    swap(nums, left, index);

    // lt 是小于 pivot 的最后一个元素的索引
    int pivot = nums[left];
    int lt = left;

    /* 循环不变量：
     * all in [left + 1, lt] < pivot
     * all in [lt + 1, i) >= pivot */
    for (int i = left + 1; i <= right; i++) {
        if (nums[i] < pivot) {
            lt++;
            swap(nums, i, lt);
        }
    }
    swap(nums, left, lt);

    return lt;
}

static void quick_sort(vector<int>& nums, int left, int right)
{
    int index = partition(nums, left, right);
    if (left > right) {
        return;
    }
    quick_sort(nums, left, index - 1);
    quick_sort(nums, index + 1, right);
}

static void quick_sort(vector<int>& nums)
{
    quick_sort(nums, 0, nums.size() - 1);
}

int main(int argc, char* argv[])
{
    vector<int> a = {10, 1000, 800, 400, 100, 300};
    quick_sort(a);
    for (auto i : a) {
        cout << i << endl;
    }
    return 0;
}
