#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int>& numbers, int target);
};

vector<int> Solution::twoSum(vector<int>& numbers, int target)
{
    const int len = numbers.size();
    int i = 0, j = len - 1, sum;

    while (i < j) {
        sum = numbers[i] + numbers[j];
        if (sum == target) {
            break;
        } else if (sum < target) {
            i++;
        } else {
            j--;
        }
    }

    return {i + 1, j + 1};
}
