#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<string> letterCombinations(string digits);

private:
    struct Letter {
        int num;
        char letter[5];
    };

    constexpr static Letter letters[] = {
        {2, "abc"}, {3, "def"},  {4, "ghi"}, {5, "jkl"},
        {6, "mno"}, {7, "pqrs"}, {8, "tuv"}, {9, "wxyz"},
    };

    void genCombinations(const string &digits, const int pos, char *s, vector<string> &out);
};

/* dfs */
void Solution::genCombinations(const string &digits, const int pos, char *s, vector<string> &out)
{
    const int size = digits.size();
    if (pos == size) {
        s[size] = 0;
        out.push_back(s);
        return;
    }

    const char *seq = letters[digits.at(pos) - '2'].letter;
    while (*seq != 0) {
        s[pos] = *seq;
        genCombinations(digits, pos + 1, s, out);
        seq++;
    }
}

vector<string> Solution::letterCombinations(string digits)
{
    vector<string> res;
    char *s = static_cast<char*>(malloc(digits.size() + 1));

    if (digits.size() == 0) {
        return {};
    }

    genCombinations(digits, 0, s, res);

    free(s);

    return res;
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
