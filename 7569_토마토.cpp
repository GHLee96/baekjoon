#include <iostream>
#include <queue>

using namespace std;

int M, N, H;
int map[101][101][101];

int dr[6] = {1, -1, 0, 0, 0, 0};
int dc[6] = {0, 0, 1, -1, 0, 0};
int dh[6] = {0, 0, 0, 0, 1, -1};

struct info {
    int h, r, c;
};

bool is_map(int r, int c, int h) {
    if (r >= 0 && r < N && c >= 0 && c < M && h >= 0 && h < H) return true;
    return false;
}

int cnt = 0;
queue<pair<info, int>> q;

int solution() {
    int ret = -1;
    int max_day = 0;

    while (!q.empty()) {
        struct info c = q.front().first;
        int day = q.front().second;
        max_day = max(max_day, day);
        q.pop();

        for (int i = 0; i < 6; i++) {
            struct info dt;
            dt.r = c.r + dr[i];
            dt.c = c.c + dc[i];
            dt.h = c.h + dh[i];

            if (is_map(dt.r, dt.c, dt.h)) {
                if (map[dt.h][dt.r][dt.c] == 0) {
                    map[dt.h][dt.r][dt.c] = 1;

                    q.push({dt, day + 1});
                    cnt--;
                }
            }
        }
    }
    if (cnt == 0) ret = max_day;

    return ret;
}

void input() {
    cin >> M >> N >> H;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                cin >> map[i][j][k];
                if (map[i][j][k] == 1) {
                    struct info a = {i, j, k};
                    q.push({a, 0});
                } else if (map[i][j][k] == 0)
                    cnt++;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    cout << solution();

    return 0;
}