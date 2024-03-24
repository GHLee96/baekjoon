#include <cstring>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int map[1005][1005];
int n_map[1005][1005];
int N, M;
int dr[4] = {0, 0, -1, 1};
int dc[4] = {1, -1, 0, 0};
int visit[1005][1005];

vector<pair<int, int>> arr;

bool is_valid(int r, int c) { return r >= 0 && r < N && c >= 0 && c < M; }

void input() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < M; j++) {
            map[i][j] = line[j] == '0' ? 0 : -1;
        }
    }
}

int get_cnt(int r, int c) {

    int ret = 1;

    arr.push_back({r, c});

    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (!is_valid(nr, nc))
            continue;

        if (visit[nr][nc])
            continue;

        if (map[nr][nc] == -1)
            continue;

        visit[nr][nc] = 1;
        ret = (ret + get_cnt(nr, nc)) % 10;
    }

    return ret;
}

int valid_cnt(int r, int c) {
    int ret = 1;

    set<int> s;

    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (!is_valid(nr, nc))
            continue;

        if (map[nr][nc] == -1)
            continue;

        if (s.count(n_map[nr][nc]))
            continue;

        s.insert(n_map[nr][nc]);

        ret = (ret + map[nr][nc]) % 10;
    }

    return ret;
}

void sol() {

    int num = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 0) {
                visit[i][j] = 1;
                int cnt = get_cnt(i, j) % 10;

                for (auto x : arr) {
                    map[x.first][x.second] = cnt;
                    n_map[x.first][x.second] = num;
                }
                num++;
                arr.clear();
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] != -1) {
                cout << 0;
            } else {
                int cnt = valid_cnt(i, j);
                cout << cnt % 10;
            }
        }
        cout << '\n';
    }
}

int main() {
    input();
    sol();

    return 0;
}