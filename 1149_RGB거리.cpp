#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    vector<vector<int>> cost;
    vector<vector<int>> dp;

    cin >> N;
    cost.resize(N + 1, vector<int>(3));
    dp.resize(N + 1, vector<int>(3, 0x7fffffff));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) cin >> cost[i][j];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (i == 0) {
                    dp[i][j] = cost[i][j];
                    continue;
                }
                if (j == k) continue;
                dp[i][j] = min(dp[i][j], dp[i - 1][k] + cost[i][j]);
            }
        }
    }

    int res = 0x7fffffff;
    for (int i = 0; i < 3; i++) {
        res = min(res, dp[N - 1][i]);
    }
    cout << res;
    return 0;
}