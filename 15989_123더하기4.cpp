#include <iostream>

using namespace std;

int dp[10005];

int arr[] = {1, 2, 3};

int sol() {

    dp[0] = 1;
    for (auto e : arr) {
        for (int i = e; i <= 10000; i++) {
            dp[i] += dp[i - e];
        }
    }

    return 0;
}

int main() {
    int T;
    cin >> T;

    sol();

    for (int tc = 1; tc <= T; tc++) {
        int n;
        cin >> n;

        cout << dp[n] << '\n';
    }

    return 0;
}