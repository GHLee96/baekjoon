#include <cstring>
#include <iostream>

using namespace std;

int N, M;
int map[1005][1005];
int cost[1005][1005][3];
int dc[3] = {-1, 0, 1};

void input() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }

    memset(cost, -1, sizeof(cost));
}

int dfs(int r, int c, int pre_d) {

    if (r == N - 1) {
        return map[r][c];
    }

    int &ret = cost[r][c][pre_d];
    if (ret != -1)
        return ret;

    ret = 0x7ffffff;

    for (int next_d = 0; next_d < 3; next_d++) {
        if (next_d == pre_d)
            continue;

        int nr = r + 1;
        int nc = c + dc[next_d];
        if (nr < 0 || nr >= N || nc < 0 || nc >= M)
            continue;

        ret = min(ret, dfs(nr, nc, next_d) + map[r][c]);
    }

    return ret;
}

void solution() {
    int min_val = 0x7ffffff;

    for (int i = 0; i < M; i++) {
        min_val = min(min_val, dfs(0, i, 111));
    }

    cout << min_val << endl;
}

int main() {
    input();
    solution();

    return 0;
}