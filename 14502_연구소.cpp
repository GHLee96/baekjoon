#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct info {
    int row, col;
};

vector<vector<int>> origin_map;
vector<vector<int>> map;

int N, M;
queue<info> virus;
vector<info> combi;
vector<info> blank;

int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

bool is_map(int r, int c) {
    if (r >= 0 && r < N && c >= 0 && c < M) return true;
    return false;
}

int max_cnt = 0;
int bfs() {
    queue<info> q = virus;

    while (!q.empty()) {
        info c = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int tr = c.row + dr[i];
            int tc = c.col + dc[i];

            if (!is_map(tr, tc)) continue;
            if (map[tr][tc] == 0) {
                map[tr][tc] = 2;
                q.push({tr, tc});
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 0) cnt++;
        }
    }
    return cnt;
}

void make_combi(int idx, int d) {
    if (d == 0) {
        map = origin_map;
        for (auto x : combi) {
            map[x.row][x.col] = 1;
        }
        max_cnt = max(max_cnt, bfs());
        return;
    }

    for (int i = idx; i < blank.size(); i++) {
        combi.push_back({blank[i]});
        make_combi(i + 1, d - 1);
        combi.pop_back();
    }
}

void input() {
    cin >> N >> M;

    origin_map.resize(N, vector<int>(M));
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            cin >> origin_map[r][c];
            if (origin_map[r][c] == 2) {
                // enqueue
                virus.push({r, c});
            } else if (origin_map[r][c] == 0) {
                blank.push_back({r, c});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    make_combi(0, 3);
    cout << max_cnt;
    return 0;
}