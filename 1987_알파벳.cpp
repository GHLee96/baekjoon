#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int R, C;
vector<vector<char>> map;
vector<vector<int>> visit;
int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};
int max_cnt = 0;

struct info {
    int r, c, route, cnt;
};

bool is_map(info a) {
    if (a.r >= 0 && a.r < R && a.c >= 0 && a.c < C) return true;
    return false;
}

bool is_in_route(info a, int tr, int tc) {
    int num = map[tr][tc] - 'A';
    if (a.route >> num & 0x01) return false;
    return true;
}

int dfs(info current) {
    struct info next;

    int num = map[current.r][current.c] - 'A';
    current.route = current.route | (1 << num);

    max_cnt = max(max_cnt, ++current.cnt);
    for (int i = 0; i < 4; i++) {
        next.r = current.r + dr[i];
        next.c = current.c + dc[i];
        next.route = current.route;
        next.cnt = current.cnt;

        if (!is_map(next)) continue;
        if (!is_in_route(current, next.r, next.c)) continue;

        dfs(next);
    }
    return 0;
}

int bfs() {
    queue<info> q;
    int r, c;
    int route = 0;
    int max_cnt = 0;
    q.push({0, 0, route, 0});

    while (!q.empty()) {
        struct info current = q.front();
        struct info next;
        q.pop();

        int num = map[current.r][current.c] - 'A';
        current.route = current.route | (1 << num);

        max_cnt = max(max_cnt, ++current.cnt);
        for (int i = 0; i < 4; i++) {
            next.r = current.r + dr[i];
            next.c = current.c + dc[i];
            next.route = current.route;
            next.cnt = current.cnt;

            if (!is_map(next)) continue;
            if (!is_in_route(current, next.r, next.c)) continue;

            q.push(next);
        }
    }

    return max_cnt;
}

void input() {
    cin >> R >> C;

    map.resize(R, vector<char>(C));
    visit.resize(R, vector<int>(C));
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> map[i][j];
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    cout << bfs();

    dfs({0, 0, 0, 0});
    cout << max_cnt;

    return 0;
}