#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        int i, j = 0;
        unordered_map<int, int> map;

        for (i = 0; i < nums.size(); ++i) {
            map.insert(make_pair(nums[i], i));
        }

        for (i = 0; i < nums.size(); ++i) {
            if (map.find(target - nums[i]) != map.end()) {
                j = map[target - nums[i]];
                if (i != j) {
                    break;
                }
            }
        }

        if (i == nums.size()) {
            return {};
        }

        return {i, j};
    }
};
