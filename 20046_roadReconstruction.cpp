#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct coord {
    int r, c, cost;

    bool operator<(coord a) const { return cost > a.cost; }
};

coord start;

vector<vector<int>> map;
vector<vector<int>> dist;

int N, M;

int dr[] = {0, 0, -1, 1};
int dc[] = {1, -1, 0, 0};

bool is_valid(coord a) { return a.r >= 0 && a.r < N && a.c >= 0 && a.c < M; }

int bfs(coord start) {
    priority_queue<coord> q;

    start.cost = map[start.r][start.c];
    q.push(start);
    dist[start.r][start.c] = start.cost;

    int res = 0;

    while (!q.empty()) {
        coord now = q.top();

        q.pop();

        if (now.cost > dist[now.r][now.c]) continue;

        for (int i = 0; i < 4; i++) {
            coord next;
            next.r = now.r + dr[i];
            next.c = now.c + dc[i];

            if (!is_valid(next)) continue;
            if (map[next.r][next.c] == -1) continue;
            if (dist[next.r][next.c] <= now.cost + map[next.r][next.c])
                continue;

            dist[next.r][next.c] = now.cost + map[next.r][next.c];

            q.push({next.r, next.c, dist[next.r][next.c]});
        }
    }

    res = dist[N - 1][M - 1];
    return res;
}

void input() {
    scanf("%d %d", &N, &M);

    map.resize(N, vector<int>(M));
    dist.resize(N, vector<int>(M, 0x7fffffff));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    start.r = 0;
    start.c = 0;
    start.cost = map[0][0];
}

int main() {
    input();

    int res = bfs(start);
    if (res == 0x7fffffff || map[start.r][start.c] == -1)
        cout << -1;
    else
        cout << res;
    return 0;
}