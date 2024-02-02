#include <iostream>
#include <vector>
using namespace std;

const int MOD = 10000;

vector<vector<int>> multiply(vector<vector<int>> A, vector<vector<int>> B) {
    vector<vector<int>> C(2, vector<int>(2, 0));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
            }
        }
    }
    return C;
}

vector<vector<int>> matrixPower(vector<vector<int>> A, long long n) {
    if (n == 1)
        return A;

    vector<vector<int>> halfPower = matrixPower(A, n / 2);
    vector<vector<int>> res = multiply(halfPower, halfPower);

    if (n % 2)
        res = multiply(res, A);

    return res;
}

int fibonacci(int n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    vector<vector<int>> A = {{1, 1}, {1, 0}};
    vector<vector<int>> resultMatrix = matrixPower(A, n - 1);
    return resultMatrix[0][0];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while (1) {
        int n;
        cin >> n;
        if (n == -1)
            break;
        int result = fibonacci(n);
        cout << result << '\n';
    }
    return 0;
}
