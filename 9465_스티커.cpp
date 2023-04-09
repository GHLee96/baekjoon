#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    // ios_base::sync_with_stdio(false); ios_base::sync_with_stdio(false);
    // cin.tie(NULL); cin.tie(NULL);
    // cout.tie(NULL); cin.tie(NULL);

    int T, n, test_case, score;

    cin >> T;
    vector<int> v[3];
    int dp[3][100001] = {
        0,
    };

    for (test_case = 1; test_case <= T; test_case++) {
        cin >> n;
        for (int i = 1; i <= 2; i++) {
            v[i].clear();
        }
        memset(dp, 0, sizeof(dp));

        for (int i = 1; i <= 2; i++) {
            for (int j = 0; j < n; j++) {
                cin >> score;
                v[i].push_back(score);
            }
        }

        dp[1][0] = v[1][0];
        dp[2][0] = v[2][0];

        dp[1][1] = dp[2][0] + v[1][1];

        dp[2][1] = dp[1][0] + v[2][1];

        for (int i = 2; i < n; i++) {
            dp[1][i] = max(dp[2][i - 2], dp[2][i - 1]) + v[1][i];
            dp[2][i] = max(dp[1][i - 2], dp[1][i - 1]) + v[2][i];
        }

        cout << max(dp[1][n - 1], dp[2][n - 1]) << "\n";
    }

    return 0;
}