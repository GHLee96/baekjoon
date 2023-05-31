#include <cstring>
#include <iostream>

using namespace std;

struct MATRIX {
    int r, c;
};

int n;
MATRIX mat[501];
int dp[501][501];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> mat[i].r >> mat[i].c;
    }

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i < n - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = 0x7fffffff;

            for (int k = i; k < j; k++) {
                int cost =
                    dp[i][k] + dp[k + 1][j] + mat[i].r * mat[k].c * mat[j].c;
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    cout << dp[0][n - 1];

    return 0;
}