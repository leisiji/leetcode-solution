#include <string>
#include <vector>

#include "listnode.hpp"

using namespace std;

class Solution
{
private:
    void backtracking(int index);
    vector<string> *out_;
    vector<string> tmp_;
    string *s_;

public:
    vector<string> restoreIpAddresses(string s);
};

void Solution::backtracking(int index)
{
    const int len = s_->length(), rest = len - index;
    const int n = tmp_.size();
    const int r = 4 - n;

    if ((r * 3) < rest || r > rest) {
        return;
    }

    if (n == 4) {
        string s;
        for (int i = 0; i < n - 1; i++) {
            s.append(tmp_.at(i));
            s.push_back('.');
        }
        s.append(tmp_.back());
        out_->push_back(s);
        return;
    }

    int num = 0;
    int c1 = s_->at(index) - '0';
    tmp_.emplace_back(to_string(c1));
    backtracking(index + 1);
    tmp_.pop_back();

    if (c1 == 0) {
        return;
    }

    if (index + 1 < len) {
        int c2 = s_->at(index + 1) - '0';
        num = c1 * 10 + c2;
        tmp_.emplace_back(to_string(num));
        backtracking(index + 2);
        tmp_.pop_back();
    }

    if (index + 2 < len) {
        int c2 = s_->at(index + 1) - '0';
        int c3 = s_->at(index + 2) - '0';
        num = c1 * 100 + c2 * 10 + c3;
        if (num <= 255) {
            tmp_.emplace_back(to_string(num));
            backtracking(index + 3);
            tmp_.pop_back();
        }
    }
}

vector<string> Solution::restoreIpAddresses(string s)
{
    vector<string> out;
    out_ = &out;
    s_ = &s;
    backtracking(0);
    return out;
}

int main(int argc, char *argv[])
{
    Solution s;
    auto ret = s.restoreIpAddresses("25525511135");
    print_vec(ret);
    auto ret1 = s.restoreIpAddresses("0000");
    print_vec(ret1);
    auto ret2 = s.restoreIpAddresses("101023");
    print_vec(ret2);
    return 0;
}
