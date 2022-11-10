#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main()
{
    string s;
    stack<char> st;

    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        st.push(s[i]);
    }

    int size = st.size();
    for (int i = 0; i < size; i++) {
        cout << st.top();
        st.pop();
    }

    cout << endl;

    return 0;
}
