#include <math.h>

#include <iostream>
#include <string>

using namespace std;

/* 不溢出的解法 */
class SolutionNotOverflow
{
private:
    uint64_t add_to_head(int counter, int num, uint64_t in);
    uint64_t count(int in, int n);

public:
    string countAndSay(int n);
};

uint64_t SolutionNotOverflow::add_to_head(int counter, int num, uint64_t in)
{
    uint64_t base = 0;
    if (in > 0) {
        base = log10(in) + 1;
    }
    return (static_cast<uint64_t>(counter * 10 + num)) * static_cast<uint64_t>(pow(10, base)) + in;
}

uint64_t SolutionNotOverflow::count(int in, int n)
{
    if (n <= 0) {
        return in;
    }

    int c = 1, mod;
    int prev = in % 10;
    in = in / 10;
    uint64_t out = 0;

    while (in > 0) {
        mod = in % 10;
        if (mod == prev) {
            c++;
        } else {
            out = add_to_head(c, prev, out);
            prev = mod;
            c = 1;
        }
        in = in / 10;
    }

    out = add_to_head(c, prev, out);

    return count(out, n - 1);
}

string SolutionNotOverflow::countAndSay(int n)
{
    int ret = count(1, n - 1);
    return std::to_string(ret);
}

/*-------------字符串解法----------------*/
class Solution {
public:
    string countAndSay(int n);
    string countAndSay(string &in, int n);
};

string Solution::countAndSay(string &in, int n)
{
    if (n == 0) {
        return in;
    }
    string out;
    int counter = 1;
    char prev = in.at(0);

    for (int i = 1; i < in.size(); i++) {
        auto tmp = in.at(i);
        if (tmp != prev) {
            out.append(std::to_string(counter));
            out.push_back(prev);
            counter = 1;
            prev = tmp;
        } else {
            counter++;
        }
    }

    out.append(std::to_string(counter));
    out.push_back(prev);

    return countAndSay(out, n - 1);
}

string Solution::countAndSay(int n)
{
    string in = "1";
    return countAndSay(in, n - 1);
}

int main(int argc, char *argv[])
{
    // SolutionNotOverflow s;
    // 会发现 n=9 就会溢出
    // for (int i = 1; i <= 10; i++) {
    //     auto ret = s.countAndSay(i);
    //     std::cout << i << ": " << ret << std::endl;
    // }

    Solution s1;
    for (int i = 1; i <= 10; i++) {
        auto ret = s1.countAndSay(i);
        std::cout << i << ": " << ret << std::endl;
    }

    return 0;
}
