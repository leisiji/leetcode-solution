#include <cstdlib>
#include <iostream>
#include <vector>

#include "../src/listnode.hpp"

using namespace std;

static int partition(int left, int right, vector<int>& arr)
{
    int lt = left;
    const int mid = (left + right) >> 1;
    const int pivot = arr[mid];

    swap(arr[left], arr[mid]);

    for (int i = left + 1; i <= right; i++) {
        if (arr[i] < pivot) {
            lt++;
            swap(arr[i], arr[lt]);
        }
    }

    swap(arr[left], arr[lt]);

    return lt;
}

static void quick_sort(int left, int right, vector<int>& arr)
{
    if (left > right) {
        return;
    }
    int mid = partition(left, right, arr);
    quick_sort(left, mid - 1, arr);
    quick_sort(mid + 1, right, arr);
}

static void quick_sort(vector<int>& arr)
{
    quick_sort(0, arr.size() - 1, arr);
}

int main(int argc, char* argv[])
{
    vector<int> a = {10, 1000, 800, 400, 100, 300};
    quick_sort(a);
    print_vec(a);
    return 0;
}
