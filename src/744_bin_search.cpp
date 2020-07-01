#include <vector>
using namespace std;
class Solution {
public:
	char nextGreatestLetter(vector<char>& letters, char target) {

		if (letters.size() == 0)
		{
			return 0;
		}

		if (target >= letters[letters.size() - 1] || target < letters[0])
		{
			return letters[0];
		}

		int left = 0;
		int right = letters.size() - 1;
		int mid = (left + right + 1) / 2;

		while (left < right)
		{
			if (mid == left + 1)
			{
				if (letters[left] > target)
				{
					mid = left;
				}
				else if (letters[mid] <= target)
				{
					mid = right;
				}
				break;
			}

			if (target >= letters[mid])
			{
				left = mid;
			}
			else
			{
				right = mid;
			}

			mid = (left + right + 1) / 2;
		}


		return letters[mid];
	}
};
