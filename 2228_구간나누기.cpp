#include <climits>
#include <cstring>
#include <iostream>

using namespace std;

const int min_val = INT_MIN / 1000;

int N, M;
int arr[105];
int dp[105][105];

int p_sum[105];

int sol(int idx, int m) {
    if (m == 0)
        return 0;

    if (idx > N)
        return min_val * 100;

    int &ret = dp[idx][m];
    if (ret != min_val)
        return ret;

    ret = sol(idx + 1, m);

    for (int i = idx; i <= N; i++) {
        ret = max(ret, p_sum[i] - p_sum[idx - 1] + sol(i + 2, m - 1));
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        p_sum[i] = p_sum[i - 1] + arr[i];
    }

    for (int i = 0; i < 105; i++) {
        for (int j = 0; j < 105; j++) {
            dp[i][j] = min_val;
        }
    }

    cout << sol(1, M);

    return 0;
}