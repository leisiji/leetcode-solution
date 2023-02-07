#include <iostream>
#include <string>
#include <string_view>
#include <vector>

using namespace std;

class Solution
{
public:
    string reverseWords(string s);
};

string Solution::reverseWords(string s)
{
    vector<string_view> stack;
    string_view sv = s;
    const int len = s.size();

    for (int i = 0; i < len;i++) {
        if (sv[i] == ' ') {
            continue;
        }
        auto start = i;
        i++;
        while (i < len) {
            if (sv[i] == ' ') {
                break;
            }
            i++;
        }
        string_view tmp = sv.substr(start, i - start);
        stack.emplace_back(tmp);
    }

    string out;
    const int len2 = stack.size() - 1;
    for (int i = 0; i < len2; i++) {
        out.append(stack.back());
        out.push_back(' ');
        stack.pop_back();
    }
    out.append(stack.back());

    return out;
}

int main(int argc, char *argv[])
{
    string a = "the sky is blue";
    Solution s;
    cout << s.reverseWords(a) << endl;
    return 0;
}
