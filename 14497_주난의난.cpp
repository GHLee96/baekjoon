#include <deque>
#include <iostream>

using namespace std;

struct coord {
    int r, c;
};

int N, M;

char arr[305][305];
int dist[305][305];

int dr[4] = {0, 0, 1, -1};
int dc[4] = {-1, 1, 0, 0};

coord start, dest;

bool is_valid(int r, int c) { return r > 0 && r <= N && c > 0 && c <= M; }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> start.r >> start.c >> dest.r >> dest.c;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> arr[i][j];
        }
    }

    deque<coord> dq;
    dist[start.r][start.c] = 1;
    dq.push_back(start);

    while (!dq.empty()) {
        coord now = dq.front();
        dq.pop_front();

        if (dest.r == now.r && dest.c == now.c) {
            cout << dist[now.r][now.c] - 1;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int nr = now.r + dr[i];
            int nc = now.c + dc[i];

            if (!is_valid(nr, nc))
                continue;

            if (dist[nr][nc])
                continue;

            coord next = {nr, nc};

            if (arr[nr][nc] == '0') {
                dist[nr][nc] = dist[now.r][now.c];
                dq.push_front(next);
            } else {
                dist[nr][nc] = dist[now.r][now.c] + 1;
                dq.push_back(next);
            }
        }
    }

    return 0;
}