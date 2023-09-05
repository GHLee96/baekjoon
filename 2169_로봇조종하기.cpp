#include <cstring>
#include <iostream>

using namespace std;

int dp[1005][1005];
int map[1005][1005];
int via[1005][1005][3];
int N, M;

void input() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> map[i][j];
        }
    }
}

int main() {
    input();

    dp[1][1] = map[1][1];
    for (int i = 1; i <= M; i++)
        dp[1][i] = dp[1][i - 1] + map[1][i];
    for (int i = 2; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            via[i][j][0] = dp[i - 1][j] + map[i][j];
            via[i][j][1] = dp[i - 1][j] + map[i][j];
        }
        for (int j = 2; j <= M; j++)
            via[i][j][0] = max(via[i][j][0], via[i][j - 1][0] + map[i][j]);
        for (int j = M - 1; j >= 1; j--)
            via[i][j][1] = max(via[i][j][1], via[i][j + 1][1] + map[i][j]);
        for (int j = 1; j <= M; j++)
            dp[i][j] = max(via[i][j][0], via[i][j][1]);
    }
    cout << dp[N][M];

    return 0;
}