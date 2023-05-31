#include <cstring>
#include <iostream>

using namespace std;

int main() {
    int l;
    string str;
    const int MOD = 1234567891;
    const int r = 31;

    cin >> l;
    cin >> str;

    long long sum = 0;
    long long r_sqare = 1;
    for (int i = 0; i < l; i++) {
        sum = (sum + (str[i] - 'a' + 1) * (r_sqare)) % MOD;
        r_sqare = r_sqare * r % MOD;
    }

    cout << sum;

    return 0;
}