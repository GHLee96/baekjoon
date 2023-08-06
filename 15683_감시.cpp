#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

struct CCTV {
    int r, c, num;
};

int N, M;

int map[8][8];

// 회전 가능 가짓수
// 4, 2, 4, 4, 1

// 우 하 좌 상
int dr[] = {0, 1, 0, -1};
int dc[] = {1, 0, -1, 0};

vector<vector<int>> dirs[6];
vector<CCTV> cctv;

int min_cnt = 0x7fffffff;
int cnt;

bool is_valid(int r, int c) { return r >= 0 && r < N && c >= 0 && c < M; }

void input() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    cnt = N * M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];

            if (map[i][j] != 0 && map[i][j] != 6) {
                cctv.push_back({i, j, map[i][j]});
                cnt--;
            } else if (map[i][j] == 6) {
                cnt--;
            }
        }
    }

    vector<int> arr[4];
    for (int i = 0; i < 4; i++) {
        arr[i].push_back(i);
    }

    for (int i = 0; i < 4; i++) {
        dirs[1].push_back(arr[i]);
    }

    for (int i = 0; i < 2; i++) {
        vector<int> tmp;
        tmp.push_back(i);
        tmp.push_back(i + 2);

        dirs[2].push_back(tmp);
    }

    for (int i = 0; i < 4; i++) {
        vector<int> tmp;
        tmp.push_back(i);
        tmp.push_back((i + 1) % 4);

        dirs[3].push_back(tmp);
    }

    for (int i = 0; i < 4; i++) {
        vector<int> tmp;
        tmp.push_back(i);
        tmp.push_back((i + 1) % 4);
        tmp.push_back((i + 2) % 4);

        dirs[4].push_back(tmp);
    }

    vector<int> tmp;
    for (int i = 0; i < 4; i++) {
        tmp.push_back(i);
    }
    dirs[5].push_back(tmp);
}

void sol(int depth) {
    if (depth == cctv.size()) {
        min_cnt = min(min_cnt, cnt);
        return;
    }

    CCTV cur = cctv[depth];

    for (int i = 0; i < dirs[cur.num].size(); i++) {
        int copy_map[8][8];
        memcpy(copy_map, map, sizeof(map));
        int copy_cnt = cnt;

        for (int j = 0; j < dirs[cur.num][i].size(); j++) {
            int dir = dirs[cur.num][i][j];

            int nr = cctv[depth].r;
            int nc = cctv[depth].c;
            while (1) {
                nr += dr[dir];
                nc += dc[dir];

                if (!is_valid(nr, nc)) break;
                if (map[nr][nc] == 6) break;

                if (map[nr][nc] == 0) {
                    map[nr][nc] = -1;
                    cnt--;
                }
            }
        }

        sol(depth + 1);
        cnt = copy_cnt;
        memcpy(map, copy_map, sizeof(copy_map));
    }
}

int main() {
    input();
    sol(0);

    cout << min_cnt;

    return 0;
}