#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct coord {
    int r, c;
};

vector<vector<int>> map;
vector<vector<int>> dist;

vector<vector<int>> visit;

int N, M;

int dr[] = {0, 0, -1, 1};
int dc[] = {1, -1, 0, 0};

int init_cnt;

bool is_valid(coord a) { return a.r >= 0 && a.r < N && a.c >= 0 && a.c < M; }

int bfs(coord start) {
    dist.clear();
    dist.resize(N, vector<int>(M));

    queue<coord> q;

    q.push(start);
    dist[start.r][start.c] = 1;

    vector<vector<int>> copy_map = map;

    int cnt = 0;

    while (!q.empty()) {
        coord now = q.front();

        q.pop();

        cnt++;
        visit[now.r][now.c] = 1;

        for (int i = 0; i < 4; i++) {
            coord next;
            next.r = now.r + dr[i];
            next.c = now.c + dc[i];

            if (!is_valid(next)) continue;

            if (map[next.r][next.c] == 0) {
                copy_map[now.r][now.c]--;
                if (copy_map[now.r][now.c] < 0) copy_map[now.r][now.c] = 0;
                continue;
            }

            if (dist[next.r][next.c]) continue;

            dist[next.r][next.c] = dist[now.r][now.c] + 1;

            q.push(next);
        }
    }

    map = copy_map;

    return cnt;
}

void input() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    map.resize(N, vector<int>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];

            if (map[i][j]) init_cnt++;
        }
    }
}

int sol() {
    int cnt = init_cnt;
    int year = 0;
    while (cnt != 0) {
        visit.clear();
        visit.resize(N, vector<int>(M));

        bool flag = false;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (map[i][j] && !visit[i][j]) {
                    cnt = bfs({i, j});
                    if (flag) return year;
                    flag = true;
                }
            }
        }

        if (!flag) return 0;
        year++;
    }

    return year;
}

int main() {
    input();
    cout << sol();

    return 0;
}