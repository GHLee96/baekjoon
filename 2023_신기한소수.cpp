#include <math.h>

#include <iostream>

using namespace std;

int N;

int is_prime(int n) {
    int r = sqrt(n);
    if (n == 1) return 0;
    for (int i = 2; i <= r; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

void is_strange(int n) {
    int ret;
    if (n / (int)pow(10, N - 1) != 0) {
        cout << n << "\n";
        return;
    }

    for (int i = 1; i <= 9; i++) {
        int next = n * 10 + i;
        if (is_prime(next)) is_strange(next);
    }
}

int main() {
    cin >> N;
    is_strange(0);

    return 0;
}