#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

struct coord {
    int r, c;
};

int N;
char map[105][105];
int visit[105][105];

int dr[4] = {0, 0, -1, 1};
int dc[4] = {1, -1, 0, 0};

bool is_valid(int r, int c) { return r >= 0 && r < N && c >= 0 && c < N; }

void bfs(coord start, int mode) {

    queue<coord> q;
    visit[start.r][start.c] = 1;
    q.push(start);

    while (!q.empty()) {
        coord now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = now.r + dr[i];
            int nc = now.c + dc[i];

            if (!is_valid(nr, nc))
                continue;
            if (visit[nr][nc])
                continue;
            if (mode == 1) {
                if (map[nr][nc] != map[now.r][now.c])
                    continue;
            } else {
                if (map[now.r][now.c] == 'R' && map[nr][nc] == 'B')
                    continue;
                else if (map[now.r][now.c] == 'G' && map[nr][nc] == 'B')
                    continue;
                else if (map[now.r][now.c] == 'B' && map[nr][nc] != 'B')
                    continue;
            }
            visit[nr][nc] = 1;
            q.push({nr, nc});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }

    int res1 = 0;
    int res2 = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (visit[i][j] == 0) {
                bfs({i, j}, 1);
                res1++;
            }
        }
    }

    memset(visit, 0, sizeof(visit));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (visit[i][j] == 0) {
                bfs({i, j}, 2);
                res2++;
            }
        }
    }

    cout << res1 << ' ' << res2 << '\n';

    return 0;
}
