#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct coord {
    int r, c, dir;

    bool operator==(const coord b) const {
        return r == b.r && c == b.c && dir == b.dir;
    }
};

vector<vector<int>> map;
vector<vector<vector<int>>> dist;

int N, M;

// 동 남 서 북
int dr[] = {0, 1, 0, -1};
int dc[] = {1, 0, -1, 0};

int init_cnt;

coord start, destination;

bool is_valid(coord a) { return a.r >= 0 && a.r < N && a.c >= 0 && a.c < M; }

int bfs() {
    dist.clear();
    dist.resize(N, vector<vector<int>>(M, vector<int>(4, 0x7fffffff)));

    queue<coord> q;

    q.push(start);
    dist[start.r][start.c][start.dir] = 0;

    int cnt = 0;

    while (!q.empty()) {
        coord now = q.front();

        q.pop();

        coord next;

        // 1, 2, 3칸 이동
        for (int i = 1; i <= 3; i++) {
            next.r = now.r + dr[now.dir] * i;
            next.c = now.c + dc[now.dir] * i;
            next.dir = now.dir;

            if (!is_valid(next)) continue;
            if (map[next.r][next.c] == 1) break;

            if (dist[next.r][next.c][next.dir] <=
                dist[now.r][now.c][now.dir] + 1)
                continue;

            dist[next.r][next.c][next.dir] = dist[now.r][now.c][now.dir] + 1;
            // if (next == destination) {
            //     return dist[now.r][now.c][now.dir] + 1;
            // }

            q.push(next);
        }

        next = now;
        // 오른쪽, 왼쪽 회전

        int cmd[2] = {1, -1};
        for (int j = 0; j < 2; j++) {
            next.dir = (now.dir + cmd[j]) % 4;
            if (next.dir < 0) next.dir += 4;

            if (dist[next.r][next.c][next.dir] <=
                dist[now.r][now.c][now.dir] + 1)
                continue;

            dist[next.r][next.c][next.dir] = dist[now.r][now.c][now.dir] + 1;
            q.push(next);
        }
    }

    if (dist[destination.r][destination.c][destination.dir] == 0x7fffffff)
        return -1;
    else
        return dist[destination.r][destination.c][destination.dir];
}

void input() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    map.resize(N, vector<int>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }

    cin >> start.r >> start.c >> start.dir;
    start.r -= 1;
    start.c -= 1;
    start.dir -= 1;
    if (start.dir == 1)
        start.dir = 2;
    else if (start.dir == 2)
        start.dir = 1;

    cin >> destination.r >> destination.c >> destination.dir;
    destination.r -= 1;
    destination.c -= 1;
    destination.dir -= 1;
    if (destination.dir == 1)
        destination.dir = 2;
    else if (destination.dir == 2)
        destination.dir = 1;
}

int main() {
    input();
    cout << bfs();

    return 0;
}