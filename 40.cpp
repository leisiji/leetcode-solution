#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

	vector<vector<int>> ans;
	vector<int> path;

	void dfs(vector<int>& candidates, int start, int target)
	{
		if (target == 0)
		{
			ans.push_back(path);
			return;
		}

		if (target < 0)
		{
			return;
		}

		for (int i = start; i < candidates.size(); ++i) {
			path.push_back(candidates[i]);
			dfs(candidates, i + 1, target - candidates[i]);
			path.pop_back();
		}
	}

	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		dfs(candidates, 0, target);
		return ans;
	}
};
