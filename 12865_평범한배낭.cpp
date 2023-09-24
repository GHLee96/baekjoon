#include <iostream>

using namespace std;

int N, K;
pair<int, int> arr[105];

int dp[105][100005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= K; j++) {
            dp[i][j] = max(dp[i - 1][j],
                           j - arr[i].first >= 0
                               ? dp[i - 1][j - arr[i].first] + arr[i].second
                               : 0);
        }
    }

    cout << dp[N][K];

    return 0;
}