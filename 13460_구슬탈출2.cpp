#include <iostream>
#include <queue>

using namespace std;
int N, M;
char map[11][11];

struct info {
    int r, c, d, dir;
};

struct info r, b, h;

int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

int visit[11][11][11][11] = {
    0,
};

int bfs() {
    // priority_queue<info, vector<info>, compare> q_r;
    // priority_queue<info, vector<info>, compare> q_b;

    queue<info> q_r;
    queue<info> q_b;
    q_r.push(r);
    q_b.push(b);

    visit[r.r][r.c][b.r][b.c] = 1;

    int ret = -1;

    while (!q_r.empty()) {
        struct info current, current_b;
        current = q_r.front();
        q_r.pop();

        current_b = q_b.front();
        q_b.pop();

        if (current.d == 10) break;

        for (int i = 0; i < 4; i++) {
            int tr = current.r + dr[i];
            int tc = current.c + dc[i];

            int tr_b = current_b.r + dr[i];
            int tc_b = current_b.c + dc[i];

            // if (map[tr][tc] == '#') continue;

            while (map[tr_b][tc_b] == '.') {
                tr_b += dr[i];
                tc_b += dc[i];
            }

            while (map[tr][tc] == '.') {
                tr += dr[i];
                tc += dc[i];
            }

            if (map[tr][tc] == 'O' && map[tr_b][tc_b] == 'O') {
                continue;
            } else if (map[tr][tc] == 'O' && map[tr_b][tc_b] != 'O') {
                return current.d + 1;
            } else if (map[tr][tc] != 'O' && map[tr_b][tc_b] == 'O') {
                continue;
            }

            if (tr == tr_b && tc == tc_b) {
                if (i == 0) {
                    if (current.c > current_b.c) {
                        tr_b -= dr[i];
                        tc_b -= dc[i];
                    } else {
                        tr -= dr[i];
                        tc -= dc[i];
                    }
                } else if (i == 1) {
                    if (current.c < current_b.c) {
                        tr_b -= dr[i];
                        tc_b -= dc[i];
                    } else {
                        tr -= dr[i];
                        tc -= dc[i];
                    }
                } else if (i == 2) {
                    if (current.r > current_b.r) {
                        tr_b -= dr[i];
                        tc_b -= dc[i];
                    } else {
                        tr -= dr[i];
                        tc -= dc[i];
                    }
                } else if (i == 3) {
                    if (current.r < current_b.r) {
                        tr_b -= dr[i];
                        tc_b -= dc[i];
                    } else {
                        tr -= dr[i];
                        tc -= dc[i];
                    }
                }
            }

            tr -= dr[i];
            tc -= dc[i];
            tr_b -= dr[i];
            tc_b -= dc[i];

            if (visit[tr][tc][tr_b][tc_b] == 1) continue;
            visit[tr][tc][tr_b][tc_b] = 1;

            q_r.push({tr, tc, current.d + 1});
            q_b.push({tr_b, tc_b, current_b.d + 1});
        }
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            if (map[i][j] == 'R') {
                r = {i, j, 0, -1};
                map[i][j] = '.';
            } else if (map[i][j] == 'B') {
                b = {i, j, 0, -1};
                map[i][j] = '.';
            } else if (map[i][j] == 'O')
                h = {i, j, 0, -1};
        }
    }

    cout << bfs();

    return 0;
}