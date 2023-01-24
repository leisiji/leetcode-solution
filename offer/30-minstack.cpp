#include <cstdint>
#include <vector>

using namespace std;

class MinStack
{
private:
    vector<int> st_, minst_{INT32_MAX};

public:
    MinStack() {}

    void push(int x)
    {
        st_.push_back(x);
        // 注意这里是小于等于，比如 push 0, 1, 0 这样的序列
        if (x <= minst_.back()) {
            minst_.push_back(x);
        }
    }

    void pop()
    {
        if (!st_.empty()) {
            if (st_.back() == minst_.back()) {
                minst_.pop_back();
            }
            st_.pop_back();
        }
    }

    int top() { return st_.back(); }

    int min() { return minst_.back(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */
