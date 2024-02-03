#include <iostream>

using namespace std;

long long N;
int main() {
    cin >> N;

    long long val = N;
    for (long long i = 2; i * i <= N; i++) {
        if (N % i == 0) {
            val = val / i * (i - 1);

            while (N % i == 0)
                N /= i;
        }
    }

    if (N != 1) {
        val = val / N * (N - 1);
    }
    cout << val;

    return 0;
}