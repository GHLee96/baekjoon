#include <cstring>
#include <iostream>

using namespace std;

int dp[10005];
int arr[25];
int N, M;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        cin >> N;

        for (int i = 1; i <= N; i++) {
            cin >> arr[i];
        }
        cin >> M;

        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for (int j = 1; j <= N; j++) {
            for (int i = arr[j]; i <= M; i++) {
                dp[i] += dp[i - arr[j]];
            }
        }

        cout << dp[M] << '\n';
    }
    return 0;
}