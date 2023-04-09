/*
 *   bfs가 아닌 dfs + dp로 풀어야한다.
 *   시간 제한!!!
 */

#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

int M, N;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int map[501][501] = {
    0,
};

int counter[501][501];

int is_map(int x, int y) {
    if (x >= 0 && x < N && y >= 0 && y < M) {
        return 1;
    } else {
        return 0;
    }
}

// int solution() {
//     int tx = 0;
//     int ty = 0;

//     queue<pair<int, int>> q;
//     q.push(make_pair(0, 0));
//     counter[0][0] = 1;

//     while (!q.empty()) {
//         int x = q.front().first;
//         int y = q.front().second;
//         q.pop();

//         for (int i = 0; i < 4; i++) {
//             tx = x + dx[i];
//             ty = y + dy[i];
//             if (is_map(tx, ty)) {
//                 if (map[x][y] > map[tx][ty]) {
//                     q.push(make_pair(tx, ty));
//                     counter[tx][ty] += counter[x][y];
//                 }
//             }
//         }
//     }

//     return 0;
// }

int solution(int x, int y) {
    if (x == N - 1 && y == M - 1) return 1;
    if (counter[x][y] != -1) return counter[x][y];

    counter[x][y] = 0;
    for (int i = 0; i < 4; i++) {
        int tx = x + dx[i];
        int ty = y + dy[i];

        if (is_map(tx, ty)) {
            if (map[x][y] > map[tx][ty]) {
                counter[x][y] += solution(tx, ty);
            }
        }
    }

    return counter[x][y];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> M >> N;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[j][i];
        }
    }
    memset(counter, -1, sizeof(counter));

    cout << solution(0, 0);

    return 0;
}