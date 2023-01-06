#include <stdint.h>

#include <stack>
#include <vector>

using namespace std;

class MinStack
{
private:
    vector<int> st;
    vector<int> minSt;

public:
    /** initialize your data structure here. */
    MinStack() { minSt.push_back(INT32_MAX); }
    void push(int x);
    void pop();
    int top();
    int getMin();
};

void MinStack::push(int x)
{
    st.push_back(x);
    // 注意这里是小于等于，比如 push 0, 1, 0 这样的序列
    if (x <= minSt.back()) {
        minSt.push_back(x);
    }
}

void MinStack::pop()
{
    if (st.empty()) {
        return;
    }

    int tmp = st.back();
    st.pop_back();

    if (minSt.back() == tmp) {
        minSt.pop_back();
    }
}

int MinStack::top()
{
    if (st.empty()) {
        return 0;
    }

    return st.back();
}

int MinStack::getMin()
{
    return minSt.back();
}
