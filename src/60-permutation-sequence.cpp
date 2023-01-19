#include <iostream>
#include <string>
#include <vector>

#include "listnode.hpp"

using namespace std;

class Solution
{
private:
    string *out_;
    int count_;
    int k_;
    vector<bool> visited_;

    void backtracking();

public:
    string getPermutation1(int n, int k);
    string getPermutation(int n, int k);
};

void Solution::backtracking()
{
    const int len = visited_.size();

    if (out_->size() == len) {
        count_++;
        return;
    }

    for (int i = 0; i < len; i++) {
        if (visited_[i] == false) {
            visited_[i] = true;
            out_->push_back(i + 1 + '0');
            backtracking();
            if (count_ == k_) {
                return;
            }
            visited_[i] = false;
            out_->pop_back();
        }
    }
}

string Solution::getPermutation1(int n, int k)
{
    string out;
    out_ = &out;
    k_ = k;
    count_ = 0;
    visited_.resize(n);
    for (int i = 0; i < n; i++) {
        visited_[i] = false;
    }
    backtracking();
    return out;
}

/* 先固定其中一个元素在第一位，会发现它的排列会有 (n - 1)! 个；数学对应关系是 n! = (n - 1)! * n
 * 令 a = (n-1)!，则第一位就是 a / ((n - 1)!)，将余数 a % (n - 1)! 带到下一个循环（第二位数）中，
 * 第二位的推算同理 */
string Solution::getPermutation(int n, int k)
{
    string out;
    vector<int> factorial(n, 0);

    factorial[0] = 1;
    for (int i = 1; i < n; i++) {
        factorial[i] = factorial[i - 1] * (i + 1);
    }

    vector<int> nums;
    for (int i = 1; i < n; i++) {
        nums.push_back(i);
    }

    k--; // 相当于在 n 个数字的全排列中找到下标为 k - 1 的那个数，因此 k 先减 1
    for (int i = n - 1; i >= 0; i--) {
        int index = k / factorial[i];
        cout << index << endl;
        out.push_back(nums[index] + '0');
        nums.erase(nums.begin() + index);
        k -= index * factorial[i];
    }

    return out;
}

int main(int argc, char *argv[])
{
    Solution s;
    cout << s.getPermutation(3, 3) << endl; // 213
    // cout << s.getPermutation(4, 9) << endl; // 2314
    return 0;
}
