/* Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...]
 * (si < ei), determine if a person could attend all meetings. */

#include <algorithm>
#include <vector>
#include <assert.h>

using namespace std;

class Solution
{
public:
    bool canAttendMeetings(vector<vector<int>> &intervals);
};

bool Solution::canAttendMeetings(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end(),
         [](const vector<int> &a, const vector<int> &b) { return a[0] < b[0]; });

    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] < intervals[i - 1][1]) {
            return false;
        }
    }

    return true;
}

int main (int argc, char *argv[])
{
    vector<vector<int>> a = {{0,30},{5,10},{15,20}};
    vector<vector<int>> b = {{7,10},{4,2}};
    Solution s;
    assert(s.canAttendMeetings(a) == false);
    assert(s.canAttendMeetings(b) == true);
    return 0;
}
