#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
private:
    // 这里将 3 个参数放到结构内部，这样节省入栈出栈的时间，只需要传递 this
    int num;
    string mStr;
    vector<string> out;
public:
    vector<string> generateParenthesis(int n);
    void generateParenthesis(const int left, const int right);
};

/* 保证左右括号数相等，如果左括号大于右括号，就添加一个右括号 */
void Solution::generateParenthesis(const int left, const int right)
{
    if (mStr.size() == (2 * num)) {
        out.push_back(mStr);
    }

    // pop_back 是要保证 dfs 结束后退回到进入分支前的状态
    if (left < num) {
        mStr.push_back('(');
        generateParenthesis(left + 1, right);
        mStr.pop_back();
    }

    if (left > right) {
        mStr.push_back(')');
        generateParenthesis(left, right + 1);
        mStr.pop_back();
    }
}

vector<string> Solution::generateParenthesis(int n)
{
    num = n;
    mStr.reserve(2 * num);

    generateParenthesis(0, 0);

    return out;
}

void test(int n)
{
    Solution s;
    auto res = s.generateParenthesis(n);
    cout << "\"";
    for (auto &i : res) {
        cout << i << ", ";
    }
    cout << "\"" << endl;
}

int main(int argc, char *argv[])
{
    test(2);
    test(3);
    test(4);
    return 0;
}
