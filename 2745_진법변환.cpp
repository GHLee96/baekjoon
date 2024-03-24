#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    long long B;
    int ans = 0;

    cin >> str >> B;

    int k = 1;
    for (int i = str.length() - 1; i >= 0; i--) {
        int num = 0;
        if (str[i] >= '0' && str[i] <= '9') {
            num = str[i] - '0';
        } else {
            num = str[i] - 'A' + 10;
        }

        ans += num * k;
        k *= B;
    }

    cout << ans << endl;

    return 0;
}