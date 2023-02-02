#include <string>
#include <vector>
#include <string_view>

#include "listnode.hpp"

using namespace std;

class Solution
{
private:
    vector<vector<string>> *out_;
    void dfs(int start);
    string_view sv_;
    vector<string> tmp_;
public:
    vector<vector<string>> partition(string s);
};

// 由于这题的 s 最长也是 16，因此可以在 dfs 过程中重复判断是否回文
static inline bool is_palindrome(string_view &s)
{
    int left = 0, right = s.size() - 1;

    while (left < right) {
        if (s[left] != s[right]) {
            return false;
        }
        left++, right--;
    }

    return true;
}

void Solution::dfs(int start)
{
    if (start == sv_.size()) {
        out_->push_back(tmp_);
        return;
    }

    for (int i = start; i < sv_.size(); i++) {
        auto sub = sv_.substr(start, i - start + 1);
        if (is_palindrome(sub)) {
            tmp_.emplace_back(string(sub));
            dfs(i + 1);
            tmp_.pop_back();
        }
    }
}

vector<vector<string>> Solution::partition(string s)
{
    vector<vector<string>> out;
    out_ = &out;
    sv_ = s;
    dfs(0);
    return out;
}

int main (int argc, char *argv[])
{
    string a = "aab";
    Solution s;
    print_vec_vec(s.partition(a));
    return 0;
}
