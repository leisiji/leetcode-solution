#include <atomic>
#include <condition_variable>
#include <functional>
#include <mutex>
using namespace std;

class Foo
{
public:
    Foo() {}
    int count = 0;
    mutex m;
    condition_variable cv;

    void first(function<void()> printFirst)
    {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        lock_guard<mutex> lk(m);
        count = 1;
        cv.notify_all();
    }

    void second(function<void()> printSecond)
    {
        // printSecond() outputs "second". Do not change or remove this line.
        unique_lock<mutex> lk(m);
        cv.wait(lk, [&, this]() { return (count == 1); });
        printSecond();
        count = 2;
        cv.notify_all();
    }

    void third(function<void()> printThird)
    {
        // printThird() outputs "third". Do not change or remove this line.
        unique_lock<mutex> lk(m);
        cv.wait(lk, [&, this]() { return (count == 2); });
        printThird();
    }
};
