#include <iostream>

using namespace std;

long long cnt[10];

void single_cnt(long long n, long long ten) {
    while (n) {
        cnt[n % 10] += ten;
        n /= 10;
    }
}

void sol(long long a, long long b, long long ten) {

    while (a % 10 != 0 && a <= b) {
        single_cnt(a++, ten);
    }

    if (a > b)
        return;
    while (b % 10 != 9 && b >= a) {
        single_cnt(b--, ten);
    }

    long long now_cnt = b / 10 - a / 10 + 1;

    for (int i = 0; i < 10; i++) {
        cnt[i] += now_cnt * ten;
    }

    sol(a / 10, b / 10, ten * 10);
}

int main() {
    long long N;
    cin >> N;

    sol(1, N, 1);

    for (int i = 0; i < 10; i++) {
        cout << cnt[i] << ' ';
    }

    return 0;
}