#include <cctype>
#include <string>

using namespace std;

class Solution
{
public:
    bool isPalindrome(string s);
};

bool Solution::isPalindrome(string s)
{
    int left = 0, right = s.length() - 1;

    while (left < right) {
        auto l = s[left];
        if (!isalnum(l)) {
            left++;
            continue;
        }

        auto r = s[right];
        if (!isalnum(r)) {
            right--;
            continue;
        }
        if (tolower(l) != tolower(r)) {
            return false;
        }
        left++, right--;
    }

    return true;
}
