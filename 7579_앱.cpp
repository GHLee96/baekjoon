#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct info {
    int bytes, cost;
};

int N, M;
vector<info> v;
vector<int> dp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // input
    cin >> N >> M;
    v.resize(N + 1);

    int cost_sum = 0;
    for (int i = 1; i <= N; i++) cin >> v[i].bytes;
    for (int i = 1; i <= N; i++) {
        cin >> v[i].cost;
        cost_sum += v[i].cost;
    }
    dp.resize(cost_sum + 1);

    for (int i = 1; i <= N; i++) {
        for (int j = cost_sum; j >= v[i].cost; j--) {
            dp[j] = max(dp[j], dp[j - v[i].cost] + v[i].bytes);
        }
    }

    int ans = 0x7fffffff;
    for (int i = 1; i <= cost_sum; i++) {
        if (dp[i] >= M) {
            ans = min(ans, i);
        }
    }

    cout << ans;

    return 0;
}