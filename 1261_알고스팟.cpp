#include <deque>
#include <iostream>

using namespace std;

struct coord {
    int r, c;
};

int N, M;

char arr[105][105];
int dist[105][105];

int dr[4] = {0, 0, 1, -1};
int dc[4] = {-1, 1, 0, 0};

bool is_valid(int r, int c) { return r >= 0 && r < N && c >= 0 && c < M; }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> M >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
            dist[i][j] = 0x7fffffff;
        }
    }

    deque<coord> dq;
    dist[0][0] = 0;
    dq.push_back({0, 0});

    while (!dq.empty()) {
        coord now = dq.front();
        dq.pop_front();

        for (int i = 0; i < 4; i++) {
            int nr = now.r + dr[i];
            int nc = now.c + dc[i];

            if (!is_valid(nr, nc))
                continue;

            int val = arr[nr][nc] == '0' ? 0 : 1;

            if (dist[nr][nc] > dist[now.r][now.c] + val) {
                dist[nr][nc] = dist[now.r][now.c] + val;
                coord next = {nr, nc};

                if (val) {
                    dq.push_front(next);
                } else {
                    dq.push_back(next);
                }
            }
        }
    }

    cout << dist[N - 1][M - 1] << '\n';

    return 0;
}