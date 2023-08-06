#include <iostream>

using namespace std;

int main() {
    long long N, k;

    cin >> N;
    cin >> k;

    int l = 1;
    long long e = N * N;

    while (l < e) {
        long long mid = (l + e) / 2;
        long long cnt = 0;

        for (int i = 1; i <= N; i++) {
            cnt += min(mid / i, N);
        }

        if (cnt < k) {
            l = mid + 1;
        } else {
            e = mid;
        }
    }

    cout << l << endl;
    return 0;
}