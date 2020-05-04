#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	int jump(vector<int>& nums) {
		int steps = 0;
		int cur = 0;
		int max = 0, max_step = 0;

		if (nums.size() == 1)
		{
			return 0;
		}

		while (cur < nums.size() - 1) {

			if (cur + nums[cur] >= nums.size() - 1)
			{
				steps++;
				break;
			}

			if (nums[cur] == 1)
			{
				steps++;
				cur++;
				continue;
			}

			max = 0;
			for (int i = cur; i <= cur + nums[cur]; ++i) {
				if (max < i + nums[i]) {
					max = i + nums[i];
					max_step = i;
				}
			}

			steps++;
			cur = max_step;
		}

		return steps;
	}
};

int main(int argc, char const *argv[])
{
	//vector<int> v = {5,9,3,2,1,0,2,3,3,1,0,0};
	vector<int> v = {2,3,2,0,1};
	Solution s;
	cout << s.jump(v) << endl;
	return 0;
}
