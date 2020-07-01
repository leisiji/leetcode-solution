#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		int ans = nums.size() + 1;
		int tmp;

		for (int i = 0; i < nums.size(); ++i) {
			while (nums[i] != i + 1 && nums[i] < nums.size() && nums[i] > 0) {
				tmp = nums[i];
				if (tmp == nums[tmp]) {
					break;
				}
				nums[i] = nums[tmp-1];
				nums[tmp-1] = tmp;
			}
		}

		for (int i = 0; i < nums.size(); ++i) {
			if (nums[i] != i+1) {
				return i+1;
			}
		}

		return ans;
	}
};
int main(int argc, char *argv[])
{
	vector<int> v = {1,1};
	Solution s;
	std::cout << s.firstMissingPositive(v) << std::endl;
	
	return 0;
}
