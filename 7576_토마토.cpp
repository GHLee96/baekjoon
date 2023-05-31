#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int M, N;
int map[1001][1001];
queue<pair<int, int>> rotten;
int visit[1001][1001] = {
    0,
};
int n_tommato = 0;

int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

bool is_map(int r, int c) { return r < N && r >= 0 && c < M && c >= 0; }

struct info {
    int r, c, d;
};

int bfs() {
    queue<info> q;

    int r;
    int c;
    int d = 0;
    while (!rotten.empty()) {
        r = rotten.front().first;
        c = rotten.front().second;
        rotten.pop();
        q.push({r, c, 0});
        visit[r][c] = 1;
    }

    while (!q.empty()) {
        r = q.front().r;
        c = q.front().c;
        d = q.front().d;
        q.pop();

        if (map[r][c] == 0) n_tommato--;
        if (n_tommato == 0) return d;

        // cout << r << c << d << endl;

        for (int i = 0; i < 4; i++) {
            int tr = r + dr[i];
            int tc = c + dc[i];
            int td = d + 1;

            if (is_map(tr, tc) && map[tr][tc] != -1 && visit[tr][tc] == 0) {
                q.push({tr, tc, td});
                visit[tr][tc] = 1;
            }
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> M >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            if (map[i][j] == 1)
                rotten.push({i, j});
            else if (map[i][j] == 0)
                n_tommato++;
        }
    }

    if (n_tommato == 0)
        cout << "0";
    else
        cout << bfs();

    return 0;
}