#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string a, b;
    cin >> a >> b;

    int len_a = a.length();
    int len_b = b.length();

    vector<vector<int>> dp(len_a / 3 + 1, vector<int>(len_b / 3 + 1));

    int n = 1;
    int m = 1;
    for (int i = 0; i < len_a; i += 3) {
        m = 1;
        for (int j = 0; j < len_b; j += 3) {
            if (!strncmp(&a[i], &b[j], 3)) {
                dp[n][m] = dp[n - 1][m - 1] + 1;
            } else {
                dp[n][m] = max(dp[n][m - 1], dp[n - 1][m]);
            }
            m++;
        }
        n++;
    }

    cout << dp[len_a / 3][len_b / 3];

    return 0;
}