#include <iostream>

using namespace std;

long long power(long long a, long long b, long long c) {
    if (b == 0)
        return 1;

    else if (b == 1)
        return a % c;

    long long q = power(a, b / 2, c);  // idea : a^(b/2)
    if (b % 2)
        return ((q * q) % c * a) % c;
    else
        return (q * q) % c;
}

int main() {
    long long A, B, C;
    cin >> A >> B >> C;

    cout << power(A, B, C);

    return 0;
}
