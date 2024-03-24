#include <iostream>
#include <string>

using namespace std;

int cnt[2];

int main() {
    string str;
    cin >> str;

    for (int i = 0; i < str.size(); i++) {
        int num = str[i] - '0';
        cnt[num]++;
    }

    int erased = 0;
    for (int i = str.size() - 1; i > 0; i--) {
        if (str[i] == '0') {
            str.erase(i, 1);
            erased++;
        }

        if (erased == cnt[0] / 2)
            break;
    }

    erased = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '1') {
            str.erase(i--, 1);
            erased++;
        }

        if (erased == cnt[1] / 2)
            break;
    }

    cout << str << endl;
    return 0;
}