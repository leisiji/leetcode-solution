#include <string>
#include <stack>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	int longestValidParentheses(string s) {
		int ans = 0;
		stack<char> st;
		vector<int> dp(s.size(), 0);

		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(')
			{
				st.push(s[i]);
			}
			else if (s[i] == ')' && !st.empty())
			{
				st.pop();
				if (s[i-1] == '(' && i >= 2)
				{
					dp[i] = dp[i-2] + 2;
				}
				else
				{
					dp[i] = dp[i-1] + 2;
				}

				int last = i - dp[i];
				if (last >= 0)
				{
					dp[i] += dp[last];
				}
			}
		}

		for (int i = 0; i < dp.size(); ++i) {
			ans = max(dp[i], ans);
		}

		return ans;
	}
};

int main(int argc, char *argv[])
{
	string s = ")( ((((()())()()))()(()))";
	Solution solution;
	std::cout << solution.longestValidParentheses(s) << std::endl;
	return 0;
}
