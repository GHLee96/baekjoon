#include <iostream>

using namespace std;

int N, K;
int p[1005];

int make_prime() {
    p[0] = 1;
    p[1] = 1;

    int cnt = 0;
    for (int i = 2; i <= N; i++) {
        if (p[i])
            continue;

        if (++cnt == K) {
            p[i] = 1;
            return i;
        }

        for (int j = i * 2; j <= N; j += i) {
            if (p[j])
                continue;
            p[j] = 1;
            if (++cnt == K)
                return j;
        }
    }
    return 0;
}

int main() {
    cin >> N >> K;

    cout << make_prime();

    return 0;
}