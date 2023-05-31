#include <cstring>
#include <iostream>

using namespace std;

int main() {
    string str1, str2;
    int lcs[1001][1001] = {
        0,
    };
    cin >> str1 >> str2;

    int len1 = str1.length();
    int len2 = str2.length();

    for (int j = 1; j <= len2; j++) {
        for (int i = 1; i <= len1; i++) {
            if (str1[i - 1] == str2[j - 1]) {
                lcs[j][i] = lcs[j - 1][i - 1] + 1;
            } else {
                lcs[j][i] = max(lcs[j][i - 1], lcs[j - 1][i]);
            }
            cout << lcs[j][i] << " ";
        }
        cout << endl;
    }

    cout << lcs[len2][len1];

    return 0;
}