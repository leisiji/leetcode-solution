#include <vector>

/* 用两个栈实现队列 */
class CQueue
{
private:
    std::vector<int> st1, st2;
public:
    CQueue() {}

    void appendTail(int value);

    int deleteHead();
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */

void CQueue::appendTail(int value)
{
    st1.push_back(value);
}

/* 删除头节点的时间复杂度是 O(n) */
int CQueue::deleteHead()
{
    if (!st2.empty()) {
        auto ret = st2.back();
        st2.pop_back();
        return ret;
    }

    if (st1.empty()) {
        return -1;
    }

    while (!st1.empty()) {
        st2.push_back(st1.back());
        st1.pop_back();
    }

    auto ret = st2.back();
    st2.pop_back();
    return ret;
}
