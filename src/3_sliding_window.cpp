#include <iostream>
#include <string>
using namespace std;
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.size() == 0) {
            return 0;
        }

        if (s.size() == 1) {
            return 1;
        }

        int maxLen = 1, nums = 0;
        int left = 0, right = 0;
        bool m[256] = {0};
        int pop_len = 0;

        for (int i = 0; i < s.size(); ++i) {
            if (m[s[i]] == false) {
                m[s[i]] = true;
                nums++;
                right++;
                maxLen = maxLen > nums ? maxLen : nums;
            } else {
                pop_len = 0;
                while (s[left] != s[i]) {
                    m[s[left]] = false;
                    left++;
                    pop_len++;
                }

                // jump over the same
                left++;
                nums -= pop_len;
            }
        }

        return maxLen;
    }
};

int main(int argc, char *argv[])
{
    string s = "aaaa";
    Solution su;
    cout << su.lengthOfLongestSubstring(s) << endl;
    return 0;
}
