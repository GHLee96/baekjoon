#include <algorithm>
#include <iostream>
#include <vector>
#define INF 0x7fffff00
using namespace std;

vector<int> set_coin;
int dp[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k, coin;
    cin >> n >> k;

    for (int i = 1; i <= k; i++) {
        dp[i] = INF;
    }
    for (int i = 0; i < n; i++) {
        cin >> coin;
        set_coin.push_back(coin);
        dp[coin] = 1;
    }

    // sort(set_coin.begin(), set_coin.end());

    if (set_coin[0] > k) {
        cout << "-1";
        return 0;
    }

    // for (int j = set_coin[0]; j <= k; j++) {
    //     for (int i = 0; i < n; i++) {
    //         if (j >= set_coin[i]) {
    //             min(dp[j], dp[j - set_coin[i]] + 1);
    //         }
    //     }
    // }
    for (int i = 0; i < n; i++) {
        for (int j = set_coin[i]; j <= k; j++) {
            if (j >= set_coin[i]) {
                dp[j] = min(dp[j], dp[j - set_coin[i]] + 1);
            }
        }
    }

    if (dp[k] == INF)
        cout << "-1";
    else
        cout << dp[k];

    return 0;
}