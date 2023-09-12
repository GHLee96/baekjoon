#include <cstring>
#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct info {
    int r, c, cost, k;

    bool operator<(info right) const { return cost > right.cost; }
};

int N, M, K;
int map[1005][1005];
int visit[1005][1005][11];

int dr[4] = {0, 0, -1, 1};
int dc[4] = {-1, 1, 0, 0};

void input() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> K;

    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;

        for (int j = 0; j < M; j++) {
            map[i][j] = str[j] - '0';
        }
    }
}

int solution() {
    priority_queue<info> q;

    q.push({0, 0, 1, 0});
    visit[0][0][0] = 1;

    while (!q.empty()) {
        info now = q.top();
        q.pop();

        for (int i = 0; i < 4; i++) {
            info next;
            next.r = now.r + dr[i];
            next.c = now.c + dc[i];
            next.cost = now.cost + 1;
            next.k = now.k;

            if (next.r < 0 || next.r >= N || next.c < 0 || next.c >= M)
                continue;

            if (map[next.r][next.c]) {
                if (now.k < K) {
                    next.k = now.k + 1;
                } else {
                    continue;
                }
            }

            if (visit[next.r][next.c][next.k])
                continue;

            visit[next.r][next.c][next.k] = 1;

            if (next.r == N - 1 && next.c == M - 1) {
                return next.cost;
            }

            q.push(next);
        }
    }

    return -1;
}

int main() {
    input();
    cout << solution();

    return 0;
}