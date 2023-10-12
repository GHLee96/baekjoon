#include <cstring>
#include <iostream>

using namespace std;

struct Coin {
    int value;
    int count;
};

Coin coins[105];
int dp[100005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    n = 3;

    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;

        int total_value = 0;
        int max_cnt = 0;
        for (int j = 0; j < m; j++) {
            cin >> coins[j].value >> coins[j].count;
            total_value += coins[j].value * coins[j].count;
            max_cnt = max(max_cnt, coins[j].count);
        }

        if (total_value % 2) {
            cout << 0 << '\n';
            continue;
        }

        memset(dp, 0, sizeof(dp));
        dp[0] = 1;

        for (int j = 0; j < m; j++) {
            for (int l = total_value / 2; l >= coins[j].value; l--) {
                if (dp[l - coins[j].value]) {
                    for (int k = 0; k < coins[j].count; k++) {
                        if (l + coins[j].value * k > total_value / 2)
                            break;
                        dp[l + coins[j].value * k] = 1;
                    }
                }
            }
        }

        if (dp[total_value / 2]) {
            cout << 1 << '\n';
        } else {
            cout << 0 << '\n';
        }
    }

    return 0;
}
