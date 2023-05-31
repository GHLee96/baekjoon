#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    int len_a = a.length();
    int len_b = b.length();

    vector<vector<int>> dp(len_a + 1, vector<int>(len_b + 1));

    for (int i = 0; i < len_a; i++) {
        for (int j = 0; j < len_b; j++) {
            if (a[i] == b[j])
                dp[i + 1][j + 1] = dp[i][j] + 1;
            else
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
        }
    }
    cout << dp[len_a][len_b] << endl;

    vector<char> res(dp[len_a][len_b]);
    int cnt = dp[len_a][len_b] - 1;
    int i = len_a;
    int j = len_b;

    while (cnt >= 0) {
        if (dp[i][j] != dp[i][j - 1] && dp[i][j] != dp[i - 1][j]) {
            res[cnt--] = b[j - 1];
            i--;
            j--;
        } else {
            if (dp[i - 1][j] > dp[i][j - 1]) {
                i--;
            } else {
                j--;
            }
        }
    }

    for (auto x : res) cout << x;
    return 0;
}