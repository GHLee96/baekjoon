
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

struct coord {
    int r, c;

    bool operator<(coord b) const {
        if (r == b.r) return c < b.c;
        return r < b.r;
    }
};

struct Texi {
    int r, c, fuel;
} texi;

int N, M;

vector<vector<int>> Map;
vector<vector<int>> dist;
map<int, coord> customer;
coord dest;
int recover;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

bool is_valid(int r, int c) { return r >= 0 && r < N && c >= 0 && c < N; }

int bfs(coord start, int mode) {
    dist.clear();
    dist.resize(N, vector<int>(N, 0x7fffffff));

    queue<coord> q;
    q.push(start);
    dist[start.r][start.c] = 0;

    vector<coord> arr;

    if (mode == 0 && Map[start.r][start.c] > 1 &&
        customer[Map[start.r][start.c]].r != -1) {
        dest = customer[Map[start.r][start.c]];
        customer[Map[start.r][start.c]] = {-1, -1};

        return dist[start.r][start.c];
    }

    bool flag = false;
    int min_dis = 0x7fffffff;

    while (!q.empty()) {
        coord now = q.front();
        q.pop();

        if (flag && min_dis == dist[now.r][now.c]) break;

        for (int i = 0; i < 4; i++) {
            int nr = now.r + dr[i];
            int nc = now.c + dc[i];

            if (!is_valid(nr, nc)) continue;
            if (Map[nr][nc] == 1) continue;

            if (dist[nr][nc] <= dist[now.r][now.c] + 1) continue;
            dist[nr][nc] = dist[now.r][now.c] + 1;

            if (texi.fuel < dist[nr][nc]) {
                // 연료 부족
                texi.fuel = -1;
                return -1;
            }

            if (mode == 0 && Map[nr][nc] > 1 && customer[Map[nr][nc]].r != -1) {
                // 승객
                min_dis = dist[nr][nc];

                flag = true;
                arr.push_back({nr, nc});
            }

            if (mode == 1 && nr == dest.r && nc == dest.c) {
                // 목적지
                texi.fuel -= dist[nr][nc];
                texi.r = nr;
                texi.c = nc;

                recover = dist[nr][nc];
                return dist[nr][nc];
            }

            q.push({nr, nc});
        }
    }

    if (flag) {
        sort(arr.begin(), arr.end());

        int nr;
        int nc;
        for (auto x : arr) {
            nr = x.r;
            nc = x.c;
            dest = customer[Map[nr][nc]];
            if (dest.r != -1) break;
        }

        if (dest.r == -1) {
            texi.fuel = -1;
            return -1;
        }

        customer[Map[nr][nc]] = {-1, -1};
        texi.fuel -= dist[nr][nc];
        texi.r = nr;
        texi.c = nc;
        return dist[nr][nc];
    }

    texi.fuel = -1;
    return -1;
}

void input() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    cin >> texi.fuel;

    Map.resize(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> Map[i][j];
        }
    }

    cin >> texi.r >> texi.c;
    texi.r -= 1;
    texi.c -= 1;
    for (int i = 0; i < M; i++) {
        coord now, next;
        cin >> now.r >> now.c;
        cin >> next.r >> next.c;

        now.r -= 1;
        now.c -= 1;
        next.r -= 1;
        next.c -= 1;
        Map[now.r][now.c] = 2 + i;

        customer[2 + i] = next;
    }
}

int main() {
    input();

    for (int i = 0; i < M; i++) {
        bfs({texi.r, texi.c}, 0);
        if (texi.fuel < 0) break;

        bfs({texi.r, texi.c}, 1);
        if (texi.fuel < 0) break;

        texi.fuel += recover * 2;
    }
    cout << texi.fuel;
    return 0;
}