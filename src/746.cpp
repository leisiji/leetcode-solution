#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	int minCostClimbingStairs(vector<int>& cost) {

		if (cost.size() == 0)
		{
			return 0;
		}

		int min = 0;
		int min_dp = 0;
		vector<int> dp(cost.size(), 0);
		
		if (cost.size() == 1)
		{
			return cost[0];
		}
		dp[0] = cost[0];
		dp[1] = cost[1];

		for (int i = 2; i < cost.size(); ++i) {
			min_dp = dp[i-1] > dp[i-2] ? dp[i-2] : dp[i-1];
			dp[i] = min_dp + cost[i];
		}

		min = dp[cost.size() - 1] > dp[cost.size() - 2] ? dp[cost.size()-2] : dp[cost.size()-1];

		return min;
	}
};

int main(int argc, char *argv[])
{
	vector<int> cost = {10, 15, 20};
	Solution s;
	cout << s.minCostClimbingStairs(cost) << endl;
	return 0;
}
