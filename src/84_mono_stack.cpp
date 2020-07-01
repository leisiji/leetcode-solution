#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		if (heights.empty()) {
			return 0;
		}

		int max = heights[0];
		stack<int> monoSt;
		heights.push_back(0); // 最后强制将单调栈所有元素弹出计算
		heights.insert(heights.begin(), 0);
		monoSt.push(0);

		for (int i = 1; i < heights.size(); i++) {
			int right = monoSt.top(); // 单调栈中的最大值

			while (!monoSt.empty() && heights[monoSt.top()] > heights[i])
			{
				int cur = monoSt.top();
				monoSt.pop();
				if (!monoSt.empty()) {
					// left 是单调栈栈顶对应输入的后一个元素
					// 因为后一个元素始终比栈顶要大，否则后一个元素才是栈顶
					int left = monoSt.top() + 1;
					int area = (right - left + 1) * heights[cur];
					if (area > max)
					{
						max = area;
					}
				}
			}

			monoSt.push(i);
		}

		return max;
	}
};

int main(int argc, char *argv[])
{
	vector<int> heights({1,3,2,4});
	Solution s;
	cout << s.largestRectangleArea(heights) << endl;
	return 0;
}
