#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<int> > map;

bool is_map(int r, int c) { return r >= 0 && r < N && c >= 0 && c < M; }

int get_max_sum() {
    int res = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int sum = 0;

            // ____
            res = max(
                res, map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i][j + 3]);

            // |
            res = max(
                res, map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 3][j]);

            // ㅁ
            res = max(res, map[i][j] + map[i][j + 1] + map[i + 1][j] +
                               map[i + 1][j + 1]);

            // L
            sum = 0;
            for (int k = 0; k < 3; k++) {
                for (int l = 0; l < 2; l++) {
                    sum += map[i + k][j + l];
                }
            }
            res = max(res, sum - map[i][j] - map[i + 1][j]);
            res = max(res, sum - map[i + 1][j] - map[i + 2][j]);
            res = max(res, sum - map[i][j + 1] - map[i + 1][j + 1]);
            res = max(res, sum - map[i + 1][j + 1] - map[i + 2][j + 1]);

            // ㄹ
            res = max(res, sum - map[i][j + 1] - map[i + 2][j]);
            res = max(res, sum - map[i][j] - map[i + 2][j + 1]);

            // ㅏ ㅓ
            res = max(res, sum - map[i][j + 1] - map[i + 2][j + 1]);
            res = max(res, sum - map[i][j] - map[i + 2][j]);

            // |__
            sum = 0;
            for (int k = 0; k < 2; k++) {
                for (int l = 0; l < 3; l++) {
                    sum += map[i + k][j + l];
                }
            }
            res = max(res, sum - map[i][j] - map[i][j + 1]);
            res = max(res, sum - map[i][j + 1] - map[i][j + 2]);
            res = max(res, sum - map[i + 1][j] - map[i + 1][j + 1]);
            res = max(res, sum - map[i + 1][j + 1] - map[i + 1][j + 2]);

            // ㄹ 회전
            res = max(res, sum - map[i][j] - map[i + 1][j + 2]);
            res = max(res, sum - map[i][j + 2] - map[i + 1][j]);

            // ㅜ ㅗ
            res = max(res, sum - map[i][j] - map[i][j + 2]);
            res = max(res, sum - map[i + 1][j] - map[i + 1][j + 2]);
        }
    }
    return res;
}

void input() {
    cin >> N >> M;

    map.resize(N + 4, vector<int>(M + 4));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();

    cout << get_max_sum();

    return 0;
}