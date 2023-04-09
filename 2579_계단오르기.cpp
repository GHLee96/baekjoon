#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> v(301);
int dp[301] = {
    0,
};

/* int check(int idx, vector<int> s) {
    if (idx < 3) return 1;

    for (int i = idx - 1; i >= idx - 2; i--) {
        if (s[i] != 1) return 1;
    }

    return 0;
} */

int solution(int idx) {
    dp[0] = 0;
    dp[1] = v[1];
    dp[2] = dp[1] + v[2];
    dp[3] = max(dp[1] + v[3], v[2] + v[3]);

    int temp;
    for (int i = 4; i <= N; i++) {
        dp[i] = max(dp[i - 3] + v[i - 1] + v[i], dp[i - 2] + v[i]);
    }

    return dp[N];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> v[i];
    }

    cout << solution(0);

    /* for (int i = 0; i <= N; i++) {
        cout << dp[i] << " ";
    } */

    return 0;
}