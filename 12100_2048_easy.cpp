#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct coord {
    int row, col;
};

int N;  // 보드의 크기 N * N
vector<vector<int>> origin_map;
vector<vector<int>> map;
vector<vector<int>> is_merged;

bool is_map(int r, int c) {
    if (r >= 0 && r < N && c >= 0 && c < N) return true;
    return false;
}

void input() {
    cin >> N;

    origin_map.resize(N, vector<int>(N));
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            cin >> origin_map[r][c];
        }
    }
    map = origin_map;
}

void move_to(int dir) {
    is_merged.clear();
    is_merged.resize(N, vector<int>(N));
    if (dir == 1) {
        // up

        for (int r = 1; r < N; r++) {
            for (int c = 0; c < N; c++) {
                int tr = r - 1;
                int tc = c;
                int cr = r;
                int cc = c;

                if (map[r][c] == 0) continue;
                if (!is_map(tr, tc)) continue;

                bool check = false;
                while (is_map(tr, tc) && is_merged[tr][tc] == 0 &&
                       (map[tr][tc] == 0 || map[tr][tc] == map[cr][cc])) {
                    if (map[tr][tc] == 0) {
                        map[tr][tc] = map[cr][cc];
                    } else if (map[tr][tc] == map[cr][cc]) {
                        if (!check) {
                            map[tr][tc] += map[cr][cc];
                            is_merged[tr][tc] = 1;
                            check = true;
                        } else {
                            break;
                        }
                    }
                    map[cr][cc] = 0;

                    tr -= 1;
                    cr -= 1;
                }
            }
        }
    } else if (dir == 2) {
        // down

        for (int r = N - 2; r >= 0; r--) {
            for (int c = 0; c < N; c++) {
                int tr = r + 1;
                int tc = c;
                int cr = r;
                int cc = c;

                if (map[r][c] == 0) continue;
                if (!is_map(tr, tc)) continue;

                bool check = false;
                while (is_map(tr, tc) && is_merged[tr][tc] == 0 &&
                       (map[tr][tc] == 0 || map[tr][tc] == map[cr][cc])) {
                    if (map[tr][tc] == 0) {
                        map[tr][tc] = map[cr][cc];
                    } else if (map[tr][tc] == map[cr][cc]) {
                        if (!check) {
                            map[tr][tc] += map[cr][cc];
                            is_merged[tr][tc] = 1;
                            check = true;
                        } else {
                            break;
                        }
                    }
                    map[cr][cc] = 0;

                    tr += 1;
                    cr += 1;
                }
            }
        }
    } else if (dir == 3) {
        // left

        for (int c = 1; c < N; c++) {
            for (int r = 0; r < N; r++) {
                int tr = r;
                int tc = c - 1;
                int cr = r;
                int cc = c;

                if (map[r][c] == 0) continue;
                if (!is_map(tr, tc)) continue;

                bool check = false;
                while (is_map(tr, tc) && is_merged[tr][tc] == 0 &&
                       (map[tr][tc] == 0 || map[tr][tc] == map[cr][cc])) {
                    if (map[tr][tc] == 0) {
                        map[tr][tc] = map[cr][cc];
                    } else if (map[tr][tc] == map[cr][cc]) {
                        if (!check) {
                            map[tr][tc] += map[cr][cc];
                            is_merged[tr][tc] = 1;
                            check = true;
                        } else {
                            break;
                        }
                    }
                    map[cr][cc] = 0;

                    tc -= 1;
                    cc -= 1;
                }
            }
        }
    } else if (dir == 4) {
        // right

        for (int c = N - 2; c >= 0; c--) {
            for (int r = 0; r < N; r++) {
                int tr = r;
                int tc = c + 1;
                int cr = r;
                int cc = c;

                if (map[r][c] == 0) continue;
                if (!is_map(tr, tc)) continue;

                bool check = false;
                while (is_map(tr, tc) && is_merged[tr][tc] == 0 &&
                       (map[tr][tc] == 0 || map[tr][tc] == map[cr][cc])) {
                    if (map[tr][tc] == 0) {
                        map[tr][tc] = map[cr][cc];
                    } else if (map[tr][tc] == map[cr][cc]) {
                        if (!check) {
                            map[tr][tc] += map[cr][cc];
                            is_merged[tr][tc] = 1;
                            check = true;
                        } else {
                            break;
                        }
                    }
                    map[cr][cc] = 0;

                    tc += 1;
                    cc += 1;
                }
            }
        }
    }
}

int max_val = 0;

void move(int d) {
    if (d == 0) {
        // 가장 큰 블록 찾기
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                max_val = max(max_val, map[i][j]);
            }
        }
        return;
    }

    for (int i = 1; i <= 4; i++) {
        // 상하좌우로 움직이기

        vector<vector<int>> temp = map;
        move_to(i);
        move(d - 1);
        map = temp;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    move(5);
    cout << max_val;
    return 0;
}