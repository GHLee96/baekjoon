#include <iostream>
#include <vector>

using namespace std;

struct info {
    int start, cost;
};

int N, D;

vector<info> arr[10005];
int dp[10005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> D;

    for (int i = 0; i < N; i++) {
        int s, e, c;
        cin >> s >> e >> c;

        arr[e].push_back({s, c});
    }

    for (int i = 1; i <= D; i++)
        dp[i] = 0x7ffffff;

    for (int i = 1; i <= D; i++) {
        if (arr[i].size()) {
            for (auto x : arr[i]) {
                dp[i] = min(dp[i - 1] + 1, min(dp[x.start] + x.cost, dp[i]));
            }
        } else {
            dp[i] = dp[i - 1] + 1;
        }
    }

    cout << dp[D] << endl;

    return 0;
}