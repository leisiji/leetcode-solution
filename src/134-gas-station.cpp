#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost);
};

int Solution::canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    const int len = gas.size();
    int min = 0, mini = 0, sum = 0;

    for (int i = 0; i < len; i++) {
        sum += gas[i] - cost[i];
        if (sum < min) {
            min = sum;
            mini = i + 1;
        }
    }

    if (sum < 0) {
        return -1;
    }

    return mini == len ? 0 : mini;
}

int main (int argc, char *argv[])
{
    vector<int> gas = {1,2,3,4,5}, cost = {3,4,5,1,2};
    Solution s;
    cout << s.canCompleteCircuit(gas, cost) << endl;
    return 0;
}
