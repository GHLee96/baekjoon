#include <iostream>
#include <stack>

using namespace std;

int main() {
    int T;
    string str;

    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> str;

        stack<char> st;
        bool no = false;
        for (int j = 0; j < str.length(); j++) {
            if (str[j] == '(') {
                st.push(str[j]);
            } else {
                if (!st.empty()) {
                    st.pop();
                } else {
                    cout << "NO" << endl;
                    no = true;
                    break;
                }
            }
        }
        if (!no) {
            if (st.size() != 0)
                cout << "NO" << endl;
            else
                cout << "YES" << endl;
        }
    }
    return 0;
}