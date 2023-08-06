#include <iostream>
#include <vector>

using namespace std;

int N;
vector<pair<int, int>> info;
vector<int> dp;

int sol(int day) {
    if (day - 1 > N) return 0x80000000;
    if (day == N + 1) return 0;

    int &ret = dp[day];
    if (ret != -1) return ret;

    ret = max(sol(day + 1), sol(day + info[day].first) + info[day].second);

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    info.resize(N + 1);
    dp.resize(N + 2, -1);
    for (int i = 1; i <= N; i++) {
        cin >> info[i].first >> info[i].second;
    }

    // for (int i = 0; i <= N; i++) {
    //     int days = info[i].first;
    //     int pay = info[i].second;

    //     if (i != 0) dp[i] = max(dp[i - 1], dp[i]);

    //     if (i + days - 1 > N) continue;
    //     dp[i + days] = max(dp[i + days], dp[i] + pay);
    // }

    cout << sol(1);

    return 0;
}