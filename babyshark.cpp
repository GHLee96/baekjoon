#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef struct Shark {
    int r, c, size, eat_cnt, t;
} shark;

shark baby_shark;

int N;
int map[21][21];

pair<int, int> dt[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool is_map(int r, int c) {
    if (r >= 0 && r < N && c >= 0 && c < N) return true;
    return false;
}

void input() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
            if (map[i][j] == 9) {
                baby_shark.r = i;
                baby_shark.c = j;
                map[i][j] = 0;
            }
        }
    }
    baby_shark.size = 2;
    baby_shark.eat_cnt = 0;
    baby_shark.t = 0;
}

int solution() {
    while (1) {
        int dis[21][21];
        memset(dis, -1, sizeof(dis));
        queue<pair<int, int>> q;
        q.push({baby_shark.r, baby_shark.c});
        dis[baby_shark.r][baby_shark.c] = 0;

        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            int tr;
            int tc;
            for (auto x : dt) {
                tr = r + x.first;
                tc = c + x.second;

                if (is_map(tr, tc)) {
                    if (dis[tr][tc] == -1 && map[tr][tc] <= baby_shark.size) {
                        q.push({tr, tc});
                        dis[tr][tc] = dis[r][c] + 1;
                    }
                }
            }
        }

        int min_dis = 0x7fffffff;
        bool is_eat = false;
        for (int i = N - 1; i >= 0; i--) {
            for (int j = N - 1; j >= 0; j--) {
                if (map[i][j] < baby_shark.size && map[i][j] >= 1 &&
                    dis[i][j] != -1) {
                    if (min_dis >= dis[i][j]) {
                        min_dis = dis[i][j];
                        baby_shark.r = i;
                        baby_shark.c = j;
                        is_eat = true;
                    }
                }
            }
        }

        if (!is_eat) return 0;

        baby_shark.eat_cnt++;
        if (baby_shark.eat_cnt == baby_shark.size) {
            baby_shark.eat_cnt = 0;
            baby_shark.size++;
        }
        map[baby_shark.r][baby_shark.c] = 0;
        baby_shark.t += dis[baby_shark.r][baby_shark.c];
    }

    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    solution();
    cout << baby_shark.t;

    return 0;
}