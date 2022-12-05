#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
private:
public:
    bool isValid(string s);
};

const static unordered_map<char, char> parentheses{{'{', '}'}, {'(', ')'}, {'[', ']'}};

bool Solution::isValid(string s)
{
    vector<char> stack;

    for (auto &i : s) {
        if (parentheses.find(i) != parentheses.end()) {
            stack.push_back(i);
        } else {
            if (stack.size() == 0) {
                return false;
            }
            auto left = parentheses.find(stack.back())->second;
            if (left != i) {
                return false;
            }
            stack.pop_back();
        }
    }

    if (stack.size() != 0) {
        return false;
    }

    return true;
}

int main(int argc, char *argv[])
{
    string a = "()";
    string b = "()[]{}";
    string c = "(([[{{{{}}}}]]))";
    string d = "[(]";
    Solution s;
    cout << s.isValid(a) << endl;
    cout << s.isValid(b) << endl;
    cout << s.isValid(c) << endl;
    cout << s.isValid(d) << endl;
    return 0;
}
