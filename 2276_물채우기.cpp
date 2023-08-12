#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct coord {
    int r, c, h;

    bool operator<(coord r) const { return h > r.h; }
};

int N, M;
int map[300][300];

int dr[] = {0, 0, -1, 1};
int dc[] = {1, -1, 0, 0};

int visit[300][300];

bool is_valid(coord a) { return a.r >= 0 && a.r < N && a.c >= 0 && a.c < M; }

priority_queue<coord> pq;

void set_border() {
    for (int j = 0; j < M; j++) {
        pq.push({0, j, map[0][j]});
        visit[0][j] = 1;
    }

    for (int j = 0; j < M; j++) {
        pq.push({N - 1, j, map[N - 1][j]});
        visit[N - 1][j] = 1;
    }

    for (int i = 1; i < N - 1; i++) {
        pq.push({i, 0, map[i][0]});
        visit[i][0] = 1;
    }

    for (int i = 1; i < N - 1; i++) {
        pq.push({i, M - 1, map[i][M - 1]});
        visit[i][M - 1] = 1;
    }
}

int get_max_water() {
    int max_water = 0;

    set_border();

    while (!pq.empty()) {
        coord current = pq.top();
        pq.pop();

        queue<coord> q;
        q.push(current);

        while (!q.empty()) {
            coord now = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                coord next;
                next.r = now.r + dr[i];
                next.c = now.c + dc[i];
                next.h = map[next.r][next.c];

                if (!is_valid(next)) continue;
                if (visit[next.r][next.c]) continue;
                visit[next.r][next.c] = 1;

                if (now.h >= next.h) {
                    q.push({next.r, next.c, now.h});
                    max_water += now.h - next.h;
                    continue;
                } else {
                    pq.push(next);
                }
            }
        }
    }
    return max_water;
}

void input() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> M >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }
}

int main() {
    input();
    cout << get_max_water();

    return 0;
}