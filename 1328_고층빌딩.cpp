#include <iostream>
#include <vector>

#define MOD 1000000007

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, L, R;
    cin >> N >> L >> R;

    long long dp[101][101][101] = {
        0,
    };

    dp[1][1][1] = 1;
    dp[2][2][1] = 1;
    dp[2][1][2] = 1;

    for (int i = 3; i <= N; i++) {
        for (int j = 1; j <= L; j++) {
            for (int k = 1; k <= R; k++) {
                dp[i][j][k] = (dp[i - 1][j - 1][k] + dp[i - 1][j][k - 1] +
                               dp[i - 1][j][k] * (i - 2)) %
                              MOD;
            }
        }
    }

    cout << dp[N][L][R];
    return 0;
}
