#include <string>
using namespace std;

class Solution {
public:
	string multiply(string num1, string num2) {
		string result;
		int len1 = num1.length(), len2 = num2.length();

		if (len1 == 0 || len2 == 0)
			return "";

		if (num1.c_str()[0] == '0' || num2.c_str()[0] == '0')
			return "0";

		int productMaxLen = len1 + len2;

		for (int i = 0; i < productMaxLen; ++i) {
			
		}

		return result;
	}
};
int main(int argc, char *argv[])
{
	return 0;
}
