#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int palindrome(string str) {
    int i, j;
    int size = str.size();

    if (size % 2 == 1) {
        i = size / 2 - 1;
        j = size / 2 + 1;
    } else {
        i = size / 2 - 1;
        j = size / 2;
    }

    int count = 0;
    while (i >= 0 && j <= size) {
        if (str[i--] != str[j++]) {
            return 0;
        }
    }

    return 1;
}

int solution(string s) {
    int i = 0;
    int j = s.length() - 1;

    if (palindrome(s)) return 0;

    while (i != j) {
        if (s[i] != s[j]) {
            string t1 = s;
            string t2 = s;
            if (palindrome(t1.erase(i, 1)) || palindrome(t2.erase(j, 1)))
                return 1;
            else
                return 2;
        }
        i++;
        j--;
    }

    return 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        string str;
        cin >> str;

        cout << solution(str) << "\n";
    }
    return 0;
}