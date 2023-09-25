#include <cmath>
#include <cstring>
#include <iostream>

using namespace std;

int dp[10005];
int arr[25];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        int N, M;
        cin >> N;

        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= N; i++) {
            cin >> arr[i];
        }

        cin >> M;

        dp[0] = 1;
        for (int i = 1; i <= N; i++) {
            for (int j = arr[i]; j <= M; j++) {
                if (j - arr[i] >= 0)
                    dp[j] += dp[j - arr[i]];
            }
        }

        cout << dp[M] << '\n';
    }

    return 0;
}