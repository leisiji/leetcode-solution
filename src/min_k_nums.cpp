#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class Solution {
private:
	void swap_i(vector<int>& arr, int i, int j)
	{
		int tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
	}

	int partition(vector<int>& arr, int left, int right)
	{
		int index = (left + right) / 2;
		swap_i(arr, left, index);

		int lt = left;
		int pivot = arr[left];

		for (int i = left + 1; i <= right; ++i) {
			if (arr[i] < pivot)
			{
				lt++;
				swap_i(arr, lt, i);
			}
		}
		swap_i(arr, lt, left);

		return lt;
	}

	void TopK(vector<int>& arr, int left, int right, int k)
	{
		int index = partition(arr, left, right);

		if (index == k) {
			return;
		}
		else if (index < k) {
			TopK(arr, index + 1, right, k);
		}
		else {
			TopK(arr, left, index - 1, k);
		}
	}

public:
	vector<int> getLeastNumbers(vector<int>& arr, int k) {
		if (k > arr.size() || k == 0)
		{
			return {};
		}
		else if (k == arr.size())
		{
			return arr;
		}

		TopK(arr, 0, arr.size() - 1, k - 1);

		vector<int> v(arr.begin(), arr.begin() + k);

		return v;
	}
};

#include <iostream>
int main(int argc, char *argv[])
{
	vector<int> arr = {0,0,0,2,0,5};
	Solution s;
	auto res = s.getLeastNumbers(arr, 2);

	for (auto i : res) {
		std::cout << i << std::endl;
	}

	return 0;
}
