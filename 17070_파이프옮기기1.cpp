// #include <iostream>
// #include <queue>
// #include <vector>

// using namespace std;
// enum MOVE { M_RIGHT, M_RIGHT_DOWN, M_DOWN };
// enum STATE { S_RIGHT, S_RIGHT_DOWN, S_DOWN };

// struct info {
//     enum STATE state;
//     int r, c;
// };

// int N;
// vector<vector<int>> map;

// bool is_map(int r, int c) { return r >= 0 && r < N && c >= 0 && c < N; }

// // bool check(int r, int c, enum MOVE move) {
// //     if (move == M_RIGHT) {
// //         if (!is_map(r, c + 1)) return false;
// //         if (map[r][c + 1] == 1) return false;
// //     } else if (move == M_RIGHT_DOWN) {
// //         if (!is_map(r + 1, c)) return false;
// //         if (map[r + 1][c] == 1) return false;
// //         if (!is_map(r, c + 1)) return false;
// //         if (map[r][c + 1] == 1) return false;
// //         if (!is_map(r + 1, c + 1)) return false;
// //         if (map[r + 1][c + 1] == 1) return false;
// //     } else if (move == M_DOWN) {
// //         if (!is_map(r + 1, c)) return false;
// //         if (map[r + 1][c] == 1) return false;
// //     }

// //     return true;
// // }

// // int get_case_cnt() {
// //     queue<info> q;
// //     q.push({S_RIGHT, 0, 1});

// //     int cnt = 0;
// //     while (!q.empty()) {
// //         info c = q.front();
// //         q.pop();

// //         if (c.r == N - 1 && c.c == N - 1) cnt++;

// //         if (c.state == S_RIGHT) {
// //             if (check(c.r, c.c, M_RIGHT)) {
// //                 q.push({S_RIGHT, c.r, c.c + 1});
// //             }

// //             if (check(c.r, c.c, M_RIGHT_DOWN)) {
// //                 q.push({S_RIGHT_DOWN, c.r + 1, c.c + 1});
// //             }
// //         } else if (c.state == S_DOWN) {
// //             if (check(c.r, c.c, M_DOWN)) {
// //                 q.push({S_DOWN, c.r + 1, c.c});
// //             }

// //             if (check(c.r, c.c, M_RIGHT_DOWN)) {
// //                 q.push({S_RIGHT_DOWN, c.r + 1, c.c + 1});
// //             }
// //         } else {
// //             if (check(c.r, c.c, M_RIGHT_DOWN)) {
// //                 q.push({S_RIGHT_DOWN, c.r + 1, c.c + 1});
// //             }

// //             if (check(c.r, c.c, M_DOWN)) {
// //                 q.push({S_DOWN, c.r + 1, c.c});
// //             }

// //             if (check(c.r, c.c, M_RIGHT)) {
// //                 q.push({S_RIGHT, c.r, c.c + 1});
// //             }
// //         }
// //     }

// //     return cnt;
// // }

// int dr[3] = {0, 1, 1};
// int dc[3] = {1, 0, 1};

// int dfs(int r, int c, int state) {
//     if (r == N - 1 && c == N - 1) {
//         return 1;
//     }

//     int cnt = 0;

//     for (int i = 0; i < 3; i++) {
//         int tr = r + dr[i];
//         int tc = c + dc[i];

//         if (state == 0 && i == 1 || state == 1 && i == 0) {
//             continue;
//         }

//         if (!is_map(tr, tc)) continue;
//         if (map[tr][tc] == 1) continue;

//         if (i == 2 && (map[r + 1][c] == 1 || map[r][c + 1] == 1)) continue;

//         cnt += dfs(tr, tc, i);
//     }

//     return cnt;
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     cin >> N;
//     map.resize(N, vector<int>(N));
//     for (int i = 0; i < N; i++) {
//         for (int j = 0; j < N; j++) {
//             cin >> map[i][j];
//         }
//     }

//     // cout << get_case_cnt();
//     cout << dfs(0, 1, 0);

//     return 0;
// }

/* #include <iostream>
using namespace std;

int N;
bool map[16][16];
int dp[16][16][3];

void solve() {
    dp[0][1][0] = 1;
    for (int j = 2; j < N; j++) {
        if (!map[0][j]) dp[0][j][0] = dp[0][j - 1][0];
    }

    for (int i = 1; i < N; i++) {
        for (int j = 2; j < N; j++) {
            if (!map[i][j]) {
                dp[i][j][0] = dp[i][j - 1][0] + dp[i][j - 1][1];
                dp[i][j][2] = dp[i - 1][j][1] + dp[i - 1][j][2];
                if (!map[i - 1][j] && !map[i][j - 1]) {
                    dp[i][j][1] = dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] +
                                  dp[i - 1][j - 1][2];
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) cin >> map[i][j];

    solve();

    cout << dp[N - 1][N - 1][0] + dp[N - 1][N - 1][1] + dp[N - 1][N - 1][2];
} */
