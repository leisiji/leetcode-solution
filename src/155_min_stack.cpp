#include <stack>
#include <vector>
using namespace std;
class MinStack
{
public:
    vector<int> st;
    stack<int> minSt;
    /** initialize your data structure here. */
    MinStack() { minSt.push(__INT_MAX__); }

    void push(int x)
    {
        st.push_back(x);
        if (x < minSt.top()) {
            minSt.push(x);
        }
    }

    void pop()
    {
        if (st.empty()) {
            return;
        }

        int tmp = st[st.size() - 1];
        st.pop_back();

        if (minSt.top() == tmp) {
            minSt.pop();
        }
    }

    int top()
    {
        if (st.empty()) {
            return 0;
        }

        return st[st.size() - 1];
    }

    int getMin() { return minSt.top(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
