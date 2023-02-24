#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include "listnode.hpp"

using namespace std;

class Solution
{
private:
    int num_;
    string str_;
    vector<string> out_;
    string valid_;
public:
    vector<string> generateParenthesis(int n);
    void generateParenthesis(const int left, const int right);
    void generateParenthesis1(int left);
};

/* 解法 2：利用 leetcode 20 去检查括号是否合法 */
void Solution::generateParenthesis1(int left)
{
    if (str_.size() == (2 * num_)) {
        out_.push_back(str_);
        return;
    }

    if (left < num_) {
        str_.push_back('(');
        valid_.push_back('(');
        generateParenthesis1(left + 1);
        valid_.pop_back();
        str_.pop_back();
    }

    if (valid_.size() > 0) {
        valid_.pop_back();
        str_.push_back(')');
        generateParenthesis1(left);
        valid_.push_back('(');
        str_.pop_back();
    }
}

/* 解法 1：保证左右括号数相等，如果左括号大于右括号，就添加一个右括号 */
void Solution::generateParenthesis(const int left, const int right)
{
    if (str_.size() == (2 * num_)) {
        out_.push_back(str_);
    }

    if (left < num_) {
        str_.push_back('(');
        generateParenthesis(left + 1, right);
        str_.pop_back();
    }

    if (left > right) {
        str_.push_back(')');
        generateParenthesis(left, right + 1);
        str_.pop_back();
    }
}

vector<string> Solution::generateParenthesis(int n)
{
    num_ = n;
    str_.reserve(2 * num_);

    generateParenthesis1(0);

    return out_;
}

void test(int n)
{
    Solution s;
    auto res = s.generateParenthesis(n);
    print_vec(res);
}

int main(int argc, char *argv[])
{
    test(2);
    test(3);
    test(4);
    return 0;
}
