#include <string.h>

#include <iostream>
#include <string>
#include <string_view>

using namespace std;

class Solution
{
private:
    void push(string &out, string &path, int left, int right);
public:
    string simplifyPath(string path);
};

void Solution::push(string &out, string &path, int left, int right)
{
    const char *start = path.c_str() + left + 1;
    const int len = right - left;

    if ((len - 1 == 2) && (strncmp(start, "..", 2) == 0)) {
        // 如果要优化，要保存每个 / 的位置才能应对多个 .. 的情况
        auto ret = out.find_last_of('/');
        if (ret != -1) {
            out.erase(out.begin() + ret, out.end());
        }
    } else if ((len - 1 == 1) && (*start == '.')) {
        return;
    } else {
        out.push_back('/');
        out.append(path.begin() + left + 1, path.begin() + right);
    }
}

// 也可以使用栈实现，每个目录入栈，遇到 .. 就出栈
string Solution::simplifyPath(string path)
{
    string out;
    const int len = path.length();
    int prev_slash = 0;
    char prev = '/';

    for (int i = 1; i < len; i++) {
        auto cur = path[i];
        if (cur == '/') {
            if (prev != '/') {
                push(out, path, prev_slash, i);
            }
            prev_slash = i;
        }
        prev = cur;
    }

    if (path.at(len - 1) != '/' && prev_slash != -1) {
        push(out, path, prev_slash, len);
    }
    if (out.length() == 0) {
        out.push_back('/');
    }

    return out;
}

int main(int argc, char *argv[])
{
    string a = "/home/";
    string b = "/home/../";
    string c = "/home//foo/";
    string d = "/home//foo";
    string e = "/../";
    string f = "/..";
    string g = "/.";
    string h = "/home/.";
    string i = "/home/home/home/fsfs";
    string z = "/a/./b/../../c/"; // /c
    Solution s;
    // cout << s.simplifyPath(a) << endl;
    // cout << s.simplifyPath(b) << endl;
    // cout << s.simplifyPath(e) << endl;
    // cout << s.simplifyPath(c) << endl;
    // cout << s.simplifyPath(d) << endl;
    // cout << s.simplifyPath(f) << endl;
    // cout << s.simplifyPath(g) << endl;
    // cout << s.simplifyPath(h) << endl;
    // cout << s.simplifyPath(i) << endl;
    cout << s.simplifyPath(z) << endl;
    return 0;
}
