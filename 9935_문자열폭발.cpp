#include <cstring>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string str1, explode;

    cin >> str1;
    cin >> explode;

    int size = str1.length();
    int ex_size = explode.length();
    string tmp = "";

    for (int i = 0; i < size; i++) {
        tmp += str1[i];

        int tmp_size = tmp.length();
        if (tmp_size >= ex_size) {
            bool ex = true;
            for (int j = ex_size - 1; j >= 0; j--) {
                if (tmp[tmp_size - 1 - j] != explode[ex_size - 1 - j]) {
                    ex = false;
                    break;
                }
            }
            if (ex) {
                tmp.erase(tmp.end() - ex_size, tmp.end());
            }
        }
    }

    if (tmp.length() == 0)
        cout << "FRULA";
    else
        cout << tmp;
    return 0;
}