#include <iostream>
#include <vector>

using namespace std;

int dp[31]{
    0,
};

int solution(int i, int v) {
    int result;
    v += dp[i - 2] * 2;
    if (i - 2 > 0) {
        result = solution(i - 2, v);
    } else if (i - 2 == 0) {
        return v;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    dp[0] = 1;
    dp[2] = 3;

    // dp[8] = dp[6] * dp[2] + dp[4] * 2 + dp[2] * 2 + dp[0] * 2

    for (int i = 4; i <= N; i += 2) {
        dp[i] = dp[i - 2] * dp[2] + solution(i - 2, 0);
    }

    cout << dp[N];

    return 0;
}