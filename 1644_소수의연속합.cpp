#include <math.h>

#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> c;
    vector<int> prime;
    c.resize(n + 1, 1);

    int range = sqrt(n);
    for (int i = 2; i <= range; i++) {
        if (c[i] == 0) continue;

        for (int j = 2 * i; j <= n; j += i) {
            c[j] = 0;
        }
    }
    int cnt = 0;

    for (int i = 2; i <= n; i++)
        if (c[i] != 0) {
            prime.push_back(i);
        }

    int s = 0;
    int e = 0;

    int sum = 2;
    while (e < prime.size()) {
        if (sum < n) {
            e++;
            if (e < prime.size()) sum += prime[e];
        } else if (sum > n) {
            sum -= prime[s++];
        } else if (sum == n) {
            cnt++;
            e++;
            if (e < prime.size()) sum += prime[e];
        }
    }

    cout << cnt;

    return 0;
}