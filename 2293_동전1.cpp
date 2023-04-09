#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin.tie(NULL);

    vector<int> n_coin;
    int dp[100001] = {
        0,
    };

    int n, k, coin;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> coin;
        n_coin.push_back(coin);
    }

    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = n_coin[i]; j <= k; j++) {
            dp[j] += dp[j - n_coin[i]];
        }
    }
    cout << dp[k];

    return 0;
}