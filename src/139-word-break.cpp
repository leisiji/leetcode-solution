#include <assert.h>
#include <string.h>

#include <iostream>
#include <string>
#include <string_view>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution
{
private:
    vector<string> *dict_;
    string *target_;
    vector<bool> match_;
    bool backtracking(int i);

public:
    bool wordBreak1(string s, vector<string> &wordDict);
    bool wordBreak(string s, vector<string> &wordDict);
};

/* 若使用简单的 dfs，而没有使用记忆化递归（matched_ 数组），代码会超时 */
bool Solution::backtracking(int index)
{
    const int tlen = target_->length();
    if (index == tlen) {
        return true;
    }

    if (!match_[index]) {
        return false;
    }

    for (int i = 0; i < dict_->size(); i++) {
        const auto &str = dict_->at(i);
        const auto len = str.size();
        if (tlen - index >= len) {
            if (strncmp(str.c_str(), target_->c_str() + index, len) == 0) {
                if (backtracking(index + len)) {
                    return true;
                }
            }
        }
    }
    match_[index] = false;

    return false;
}

bool Solution::wordBreak1(string s, vector<string> &wordDict)
{
    dict_ = &wordDict;
    target_ = &s;
    match_.resize(s.length());
    for (int i = 0; i < s.length(); i++) {
        match_[i] = true;
    }
    return backtracking(0);
}

/* 转化为目标字符串长度是否能通过不同长度相加起来，并通过 hashmap 加速查找字符串是否在字典中的过程 */
bool Solution::wordBreak(string s, vector<string> &wordDict)
{
    unordered_set<string_view> set(wordDict.begin(), wordDict.end());
    const int len = s.size();
    vector<bool> dp(len + 1, false);
    string_view sv = s;

    dp[0] = true;

    for (int i = 1; i <= len; i++) {
        for (int j = 0; j < i; j++) {
            auto w = sv.substr(j, i - j);
            if (set.find(w) != set.end() && dp[j]) {
                dp[i] = true;
                break;
            }
        }
    }

    return dp[len];
}

int main(int argc, char *argv[])
{
    Solution s;
    vector<string> a = {"leet", "code"};
    assert(s.wordBreak("leetcode", a));
    vector<string> b = {"cats", "dog", "sand", "and", "cat"};
    assert(!s.wordBreak("catsandog", b));

    string c =
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    vector<string> e = {"a",      "aa",      "aaa",      "aaaa",      "aaaaa",
                        "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa"};
    assert(!s.wordBreak(c, e));
    return 0;
}
