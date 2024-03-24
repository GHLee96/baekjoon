#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

struct Coord {
    int r, c;
};

int N, M;

vector<vector<vector<Coord>>> link;
int light[105][105];
int visited[105][105];

int dr[4] = {0, 0, -1, 1};
int dc[4] = {1, -1, 0, 0};

bool is_valid(Coord coord) {
    return coord.r >= 1 && coord.r <= N && coord.c >= 1 && coord.c <= N;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    link.resize(N + 1, vector<vector<Coord>>(N + 1));
    for (int i = 0; i < M; i++) {
        int x, y, a, b;

        cin >> x >> y >> a >> b;

        link[x][y].push_back({a, b});
    }

    queue<Coord> q;
    q.push({1, 1});
    light[1][1] = 1;
    visited[1][1] = 1;

    int cnt = 1;
    while (!q.empty()) {
        Coord now = q.front();

        q.pop();

        for (auto next : link[now.r][now.c]) {

            if (light[next.r][next.c])
                continue;

            light[next.r][next.c] = 1;
            cnt++;

            memset(visited, 0, sizeof(visited));
        }

        for (int i = 0; i < 4; i++) {
            int nr = now.r + dr[i];
            int nc = now.c + dc[i];

            if (!is_valid({nr, nc}))
                continue;

            if (light[nr][nc] == 0)
                continue;

            if (visited[nr][nc])
                continue;
            visited[nr][nc] = 1;

            q.push({nr, nc});
        }
    }

    cout << cnt << endl;

    return 0;
}