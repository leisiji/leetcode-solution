#include <algorithm>
#include <vector>

#include "listnode.hpp"

using namespace std;

class Solution
{
public:
    int candy(vector<int>& ratings);
};

/* 注意对于 {1, 2, 87, 87, 87, 2, 1}，分配结果应该是 [1,2,3,1,3,2,1]
 * 因为题目没有要求评分相同的孩子糖果数 */
int Solution::candy(vector<int>& ratings)
{
    const int len = ratings.size();
    vector<int> left(len, 1);
    vector<int> right(len, 1);

    for (int i = 1; i < len; i++) {
        if (ratings[i] > ratings[i - 1]) {
            left[i] = left[i - 1] + 1;
        }
    }

    for (int i = len - 1; i >= 1; i--) {
        if (ratings[i - 1] > ratings[i]) {
            right[i - 1] = right[i] + 1;
        }
    }

    int sum = 0;

    for (int i = 0; i < len; i++) {
        sum += max(left[i], right[i]);
    }

    return sum;
}

int main(int argc, char* argv[])
{
    vector<int> a = {1, 2, 87, 87, 87, 2, 1};
    Solution s;
    std::cout << s.candy(a) << std::endl;
    return 0;
}
