#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> dp(N + 1, 5000);

    dp[3] = 1;
    dp[4] = 5000;
    dp[5] = 1;
    for (int i = 6; i <= N; i++) {
        dp[i] = min(dp[i - 3] + 1, dp[i - 5] + 1);
    }

    if (dp[N] >= 5000)
        cout << "-1";
    else
        cout << dp[N];
    return 0;
}