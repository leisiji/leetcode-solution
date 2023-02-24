#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const static vector<string> letters = {
    "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz",
};

class Solution
{
private:
    int len_;
    vector<string> *out_;
    string *digits_;
    string tmp_;
    void genCombinations(const int pos);

public:
    vector<string> letterCombinations(string digits);
};

void Solution::genCombinations(const int pos)
{
    if (pos == len_) {
        out_->push_back(tmp_);
        return;
    }

    auto &letter = letters[digits_->at(pos) - '2'];

    for (auto &i : letter) {
        tmp_.push_back(i);
        genCombinations(pos + 1);
        tmp_.pop_back();
    }
}

vector<string> Solution::letterCombinations(string digits)
{
    len_ = digits.size();
    if (len_ == 0) {
        return {};
    }

    vector<string> out;
    out_ = &out;
    digits_ = &digits;

    genCombinations(0);

    return out;
}

int main(int argc, char *argv[])
{
    Solution s;

    auto ans = s.letterCombinations("234");
    for (auto &i : ans) {
        cout << i << endl;
    }

    ans = s.letterCombinations("23");
    for (auto &i : ans) {
        cout << i << endl;
    }

    return 0;
}
