#include <iostream>
#include <utility>
#include <vector>

using namespace std;

class Solution
{
private:
    vector<int>* arr_;
    int partition(int left, int right);
    void least_k(int left, int right, int k);
    void quick_sort(int left, int right);

public:
    vector<int> getLeastNumbers(vector<int>& arr, int k);
    vector<int> getMaxNumbers(vector<int>& arr, int k);
};

int Solution::partition(int left, int right)
{
    int index = (left + right) >> 1;
    int pivot = arr_->at(index);
    int lt = left;

    swap(arr_->at(index), arr_->at(left));

    /* 循环不变量：
     * all in [left + 1, lt] < pivot
     * all in [lt + 1, i) >= pivot */
    for (int i = left + 1; i <= right; i++) {
        if (arr_->at(i) < pivot) {
            lt++;
            swap(arr_->at(i), arr_->at(lt));
        }
    }

    swap(arr_->at(left), arr_->at(lt));

    return lt;
}

void Solution::quick_sort(int left, int right)
{
    if (left > right) {
        return;
    }
    int index = partition(left, right);
    quick_sort(left, index - 1);
    quick_sort(index + 1, right);
}

void Solution::least_k(int left, int right, int k)
{
    int index = partition(left, right);
    if (index < k) {
        least_k(index + 1, right, k);
    } else if (index > k) {
        least_k(left, index - 1, k);
    } else if (index == k) {
        return;
    }
}

vector<int> Solution::getLeastNumbers(vector<int>& arr, int k)
{
    if (k == 0) {
        return {};
    }
    arr_ = &arr;
    least_k(0, arr.size() - 1, k - 1);

    vector<int> out(arr.begin(), arr.begin() + k);
    return out;
}

vector<int> Solution::getMaxNumbers(vector<int>& arr, int k)
{
    arr_ = &arr;
    least_k(0, arr.size() - 1, arr.size() - k - 1);

    vector<int> out(arr.begin() + arr.size() - k, arr.end());
    return out;
}

void test_min(vector<int> &a, int k)
{
    Solution s;
    auto out = s.getLeastNumbers(a, k);
    cout << "after sort: ";
    for (auto& i : a) {
        cout << i << " ";
    }
    cout << ", out: ";
    for (auto& i : out) {
        cout << i << " ";
    }
    cout << endl;
}

void test_max(vector<int> &a, int k)
{
    Solution s;
    auto out = s.getMaxNumbers(a, k);
    cout << "after sort: ";
    for (auto& i : a) {
        cout << i << ",";
    }
    cout << ", out: ";
    for (auto& i : out) {
        cout << i << " ";
    }
    cout << endl;
}

int main(int argc, char* argv[])
{
    vector<int> v = {1, 3, 2, 7, 6, 4};
    test_min(v, 2);

    vector<int> v2 = {7, 6, 5, 4, 3, 2, 1};
    test_min(v2, 3);

    vector<int> v1 = {1, 2, 3, 4, 5, 7, 6};
    test_max(v1, 2);

    vector<int> v3 = {7, 6, 5, 4, 3, 2, 1};
    test_min(v3, 2);

    vector<int> v4 = {0,0,0,2,0,5};
    test_min(v4, 0);

    return 0;
}
