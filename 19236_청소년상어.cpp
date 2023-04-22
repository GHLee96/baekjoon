#include <cstring>
#include <iostream>

using namespace std;

const int N = 4;

pair<int, int> map[N][N];

typedef struct Info {
    int r, c;
} info;

info num_to_mat[17];
int eat_max = 0;
int n_eat = 0;

pair<int, int> dir[8] = {{-1, 0}, {-1, -1}, {0, -1}, {1, -1},
                         {1, 0},  {1, 1},   {0, 1},  {-1, 1}};

bool is_map(int r, int c) {
    if (r >= 0 && r < N && c >= 0 && c < N) return true;
    return false;
}

int move_fish() {
    // 물고기 이동
    for (int i = 1; i <= 16; i++) {
        bool is_change = false;

        if (num_to_mat[i].c == -1) continue;

        int test = n_eat;

        for (int j = 1; j <= 8; j++) {
            int n_dir = map[num_to_mat[i].r][num_to_mat[i].c].second;
            int tr = num_to_mat[i].r + dir[n_dir].first;
            int tc = num_to_mat[i].c + dir[n_dir].second;

            if (is_map(tr, tc)) {
                if (map[tr][tc].first != 0) {
                    int temp_r = num_to_mat[i].r;
                    int temp_c = num_to_mat[i].c;
                    info temp_num_to_mat = num_to_mat[i];
                    pair<int, int> temp_map = map[temp_r][temp_c];

                    map[num_to_mat[i].r][num_to_mat[i].c] = map[tr][tc];
                    num_to_mat[i] = {tr, tc};

                    if (map[tr][tc].first != -1)
                        num_to_mat[map[tr][tc].first] = temp_num_to_mat;
                    map[tr][tc] = temp_map;
                    is_change = true;
                }
            }
            if (is_change) break;
            ++map[num_to_mat[i].r][num_to_mat[i].c].second %= 8;
        }
    }
    return 0;
}

void dfs(int r, int c) {
    pair<int, int> dup[N][N];
    info dup_num[17];
    for (int i = 0; i <= 16; i++) {
        dup_num[i] = num_to_mat[i];
    }
    memcpy(dup, map, sizeof(map));

    move_fish();

    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < N; j++) {
    //         cout << map[i][j].first << map[i][j].second << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    // 상어 이동
    int shark_dir = map[num_to_mat[0].r][num_to_mat[0].c].second;
    for (int i = 1; i <= 3; i++) {
        int tr = num_to_mat[0].r + dir[shark_dir].first * i;
        int tc = num_to_mat[0].c + dir[shark_dir].second * i;
        if (is_map(tr, tc)) {
            if (map[tr][tc].first != -1) {
                pair<int, int> fish = map[tr][tc];

                n_eat += fish.first;
                num_to_mat[0] = {tr, tc};
                num_to_mat[fish.first] = {-1, -1};
                map[tr][tc].first = 0;
                map[r][c] = {-1, -1};

                dfs(tr, tc);

                n_eat -= fish.first;
                num_to_mat[0] = {r, c};
                num_to_mat[fish.first] = {tr, tc};
                map[tr][tc] = fish;
                map[r][c] = {0, shark_dir};
            }
        }
    }
    eat_max = max(eat_max, n_eat);

    memcpy(map, dup, sizeof(dup));
    for (int i = 0; i <= 16; i++) {
        num_to_mat[i] = dup_num[i];
    }
    return;
}

int main() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j].first >> map[i][j].second;
            map[i][j].second--;
            num_to_mat[map[i][j].first] = {i, j};
        }
    }

    // 상어 초기 이동
    n_eat += map[0][0].first;
    num_to_mat[0] = {0, 0};

    num_to_mat[map[0][0].first] = {-1, -1};
    map[0][0].first = 0;
    // map[0][0].second;

    dfs(0, 0);

    cout << eat_max;

    return 0;
}