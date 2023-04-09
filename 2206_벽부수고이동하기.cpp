#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

#define INF 0x7fffffff

using namespace std;

struct info {
    int x, y, is_break;
};

int N, M;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int map[1001][1001];
int dis[1001][1001][2];
bool visit[1001][1001][2] = {
    0,
};

int check(int x, int y) {
    if (x >= 1 && x <= M && y >= 1 && y <= N)
        return 1;
    else
        return 0;
}

int solution(int x, int y) {
    int tx;
    int ty;
    int is_break;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            for (int k = 0; k < 2; k++) dis[j][i][k] = INF;
        }
    }
    memset(visit, false, sizeof(visit));

    queue<info> q;
    q.push({1, 1, 0});
    dis[1][1][0] = 1;

    while (!q.empty()) {
        auto [x, y, is_break] = q.front();

        q.pop();
        if (x == N && y == M) break;
        if (visit[x][y][is_break] == true) continue;
        visit[x][y][is_break] = true;

        for (int i = 0; i < 4; i++) {
            tx = x + dx[i];
            ty = y + dy[i];

            if (!check(tx, ty)) continue;

            if (map[tx][ty] == 1 && is_break == 0 &&
                dis[tx][ty][1] > dis[x][y][is_break] + 1) {
                q.push({tx, ty, 1});
                dis[tx][ty][1] = dis[x][y][is_break] + 1;
            } else if (map[tx][ty] == 0 &&
                       dis[tx][ty][is_break] > dis[x][y][is_break] + 1) {
                q.push({tx, ty, is_break});
                dis[tx][ty][is_break] = dis[x][y][is_break] + 1;
            }
        }
    }

    // for (auto ret : dis[M][N]) {
    //     cout << ret << " ";
    // }

    if (min(dis[M][N][0], dis[M][N][1]) == INF)
        return -1;
    else
        return min(dis[M][N][0], dis[M][N][1]);
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    // cin >> N >> M;
    scanf("%d %d", &N, &M);

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            scanf("%1d", &map[j][i]);
        }
    }

    printf("%d", solution(1, 1));

    return 0;
}