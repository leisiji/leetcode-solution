#include <iostream>
#include <math.h>

class Solution {
public:
	int squareSum(int n)
	{
		int sum = 0;

		while (n > 0)
		{
			sum += pow(n % 10, 2);
			n = n / 10;
		}

		return sum;
	}

	bool isHappy(int n) {
		int slow = n, fast = n;

		do
		{
			slow = squareSum(slow);
			fast = squareSum(fast);
			fast = squareSum(fast);
		} while (slow != fast);

		return slow == 1;
	}
};

int main(int argc, char *argv[])
{
	Solution solution;
	std::cout << solution.isHappy(19) << std::endl;
	return 0;
}
