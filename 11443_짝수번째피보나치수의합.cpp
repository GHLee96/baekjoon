#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000000;

vector<vector<long long>> multiply(vector<vector<long long>> A,
                                   vector<vector<long long>> B) {
    vector<vector<long long>> C(2, vector<long long>(2, 0));
    for (long long i = 0; i < 2; i++) {
        for (long long j = 0; j < 2; j++) {
            for (long long k = 0; k < 2; k++) {
                C[i][j] = (C[i][j] + (A[i][k] * B[k][j]) % MOD) % MOD;
            }
        }
    }
    return C;
}

vector<vector<long long>> matrixPower(vector<vector<long long>> A,
                                      long long n) {
    if (n == 1)
        return A;

    vector<vector<long long>> halfPower = matrixPower(A, n / 2);
    vector<vector<long long>> res = multiply(halfPower, halfPower);

    if (n % 2)
        res = multiply(res, A);

    return res;
}

long long fibonacci(long long n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    vector<vector<long long>> A = {{1, 1}, {1, 0}};
    vector<vector<long long>> resultMatrix = matrixPower(A, n - 1);
    return resultMatrix[0][0];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        long long n;
        cin >> n;
        long long result = fibonacci(n);
        cout << result << '\n';
    }
    return 0;
}
