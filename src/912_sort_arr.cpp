#include <iostream>
#include <vector>
using namespace std;
class Solution
{
private:
    void swap_v(vector<int> &v, int i, int j)
    {
        int tmp = v[i];
        v[i] = v[j];
        v[j] = tmp;
    }

    int partition(vector<int> &v, int left, int right)
    {
        int index = (left + right) / 2;
        swap_v(v, left, index);

        int pivot = v[left];
        int lt = left;

        for (int i = left + 1; i <= right; ++i) {
            if (v[i] < pivot) {
                lt++;
                swap_v(v, i, lt);
            }
        }

        swap_v(v, left, lt);

        return lt;
    }

    void sort(vector<int> &v, int left, int right)
    {
        if (left >= right) {
            return;
        }

        int j = partition(v, left, right);
        sort(v, left, j - 1);
        sort(v, j + 1, right);
    }

public:
    vector<int> sortArray(vector<int> &nums)
    {
        vector<int> v = nums;
        if (nums.size() == 0) {
            return nums;
        }
        sort(v, 0, v.size() - 1);

        return v;
    }
};

int main(int argc, char *argv[])
{
    vector<int> v = {3, 43, 32, 323, 12, 323};
    Solution s;
    s.sortArray(v);

    for (auto i : v) {
        cout << i << ',';
    }

    cout << endl;

    return 0;
}
