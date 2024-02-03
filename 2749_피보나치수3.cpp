#include <iostream>
using namespace std;

const long long MOD = 1000000;

void matrixMultiply(long long F[2][2], long long M[2][2]) {
    long long x = (F[0][0] * M[0][0] + F[0][1] * M[1][0]) % MOD;
    long long y = (F[0][0] * M[0][1] + F[0][1] * M[1][1]) % MOD;
    long long z = (F[1][0] * M[0][0] + F[1][1] * M[1][0]) % MOD;
    long long w = (F[1][0] * M[0][1] + F[1][1] * M[1][1]) % MOD;

    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
}

// 분할 정복
void matrixPower(long long F[2][2], long long n) {
    if (n <= 1)
        return;

    long long M[2][2] = {{1, 1}, {1, 0}};
    matrixPower(F, n / 2);
    matrixMultiply(F, F);

    if (n % 2 != 0) {
        matrixMultiply(F, M);
    }
}

long long fibonacci(long long n) {
    if (n <= 1)
        return n;

    long long F[2][2] = {{1, 1}, {1, 0}};
    matrixPower(F, n - 1);

    return F[0][0];
}

int main() {
    long long n;
    cin >> n;

    long long result = fibonacci(n) % MOD;
    cout << result << endl;

    return 0;
}
