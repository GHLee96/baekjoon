#include <cstring>
#include <iostream>

using namespace std;

int N, M;
int arr[1005][1005];
int dp[1005][1005];

int get_max_candy(int r, int c) {
    if (r <= 0 || c <= 0 || r > N || c > M)
        return 0;

    int &ret = dp[r][c];
    if (ret != -1)
        return ret;

    ret = 0;
    ret = max(ret, get_max_candy(r - 1, c));
    ret = max(ret, get_max_candy(r, c - 1));
    ret = max(ret, get_max_candy(r - 1, c - 1));

    return ret = ret + arr[r][c];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    memset(dp, -1, sizeof(dp));
    for (int i = 0; i <= N; i++)
        dp[0][i] = 0;
    for (int i = 0; i <= M; i++)
        dp[i][0] = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> arr[i][j];
        }
    }

    int res = get_max_candy(N, M);
    cout << res;
    return 0;
}