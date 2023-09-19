#include <iostream>
#include <string>

using namespace std;

bool is_palindrome(string s) {
    int l = 0;
    int r = s.size() - 1;

    while (l < r) {
        if (s[l++] != s[r--])
            return false;
    }
    return true;
}

int main() {
    string str;
    cin >> str;

    if (is_palindrome(str)) {
        char c = str[0];
        bool flag = true;
        for (int i = 1; i < str.size(); i++) {
            if (str[i] != c) {
                flag = false;
                break;
            }
        }
        if (flag)
            cout << -1;
        else
            cout << str.size() - 1;
    }

    else
        cout << str.size();

    return 0;
}