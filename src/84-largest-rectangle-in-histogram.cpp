#include <assert.h>

#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int>& heights);
};

int Solution::largestRectangleArea(vector<int>& heights)
{
    int ans = 0;
    vector<int> mono_st;  // 单调递增的栈
    const int size = heights.size();

    // 创建哨兵，第一个哨兵保证 stack 永远不为空，第二个哨兵强制遍历到末尾时所有元素出栈
    heights.push_back(0);
    vector<int> h(size + 2);
    h[0] = 0;
    copy(heights.begin(), heights.end(), h.begin() + 1);
    mono_st.push_back(0);

    for (int i = 1; i < size + 2; i++) {
        while (h[mono_st.back()] > h[i]) {
            int hcur = h[mono_st.back()];
            mono_st.pop_back();
            // 这里要先出栈，因为前一个元素是小于当前栈顶的
            // 因此栈顶前一个元素的下表对应的下一个元素刚好是栈顶高度矩形的左边界
            int wcur = i - 1 - mono_st.back();
            ans = max(ans, hcur * wcur);
        }
        mono_st.push_back(i);
    }

    return ans;
}

int main(int argc, char* argv[])
{
    vector<int> a = {1, 3, 2, 4};
    vector<int> b = {2, 1, 5, 6, 2, 3};
    vector<int> c = {2, 1, 2};
    Solution s;
    assert(s.largestRectangleArea(a) == 6);
    // assert(s.largestRectangleArea(b) == 10);
    // assert(s.largestRectangleArea(c) == 3);
    return 0;
}
