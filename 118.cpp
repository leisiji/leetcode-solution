#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> result;

		if (numRows == 0)
		{
			return {};
		}

		result.push_back(vector<int>{1});

		if (numRows == 1){
			return result;
		}

		result.push_back(vector<int>{1,1});

		for (int i = 2; i < numRows; ++i) {
			vector<int> tmp;

			tmp.push_back(1);
			for (int j = 1; j < i; ++j) {
				tmp.push_back(result[i-1][j-1]+result[i-1][j]);
			}
			tmp.push_back(1);

			result.push_back(move(tmp));
		}

		return result;
	}
};

int main(int argc, char *argv[])
{
	Solution s;
	auto a = s.generate(5);
	for (auto i : a) {
		for (auto j : i) {
			cout << j << ",";
		}
		cout << endl;
	}
	return 0;
}
