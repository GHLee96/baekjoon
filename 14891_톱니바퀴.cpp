#include <cmath>
#include <iostream>

using namespace std;

int K;
int gear[5][8];
int gear_num, dir;

int left_i[5];
int right_i[5];
int top_i[5];

void input() {
    for (int i = 1; i <= 4; i++) {
        for (int j = 0; j < 8; j++) {
            scanf("%1d", &gear[i][j]);
        }
    }
    cin >> K;

    for (int i = 1; i <= 4; i++) {
        left_i[i] = 6;
        top_i[i] = 0;
        right_i[i] = 2;
    }
}

int convert_i(int i, int dir) {
    int next = i - dir;
    if (next < 0) next += 8;
    return next % 8;
}

void convert_gear(int n, int dir) {
    right_i[n] = convert_i(right_i[n], dir);
    left_i[n] = convert_i(left_i[n], dir);
    top_i[n] = convert_i(top_i[n], dir);
}

int visit[5];
void dfs(int n, int dir) {
    if (n == 0 || n == 5) return;

    visit[n] = 1;

    // 톱니 극이 다르면 회전
    if (n - 1 >= 1 && gear[n - 1][right_i[n - 1]] != gear[n][left_i[n]]) {
        if (!visit[n - 1]) dfs(n - 1, -(dir));
    }

    if (n + 1 <= 4 && gear[n + 1][left_i[n + 1]] != gear[n][right_i[n]]) {
        if (!visit[n + 1]) dfs(n + 1, -(dir));
    }

    convert_gear(n, dir);
}

int main() {
    input();

    for (int i = 0; i < K; i++) {
        scanf("%d %d", &gear_num, &dir);

        for (int i = 1; i <= 4; i++) visit[i] = 0;
        dfs(gear_num, dir);
    }

    int score = 0;
    for (int i = 1; i <= 4; i++) {
        score += gear[i][top_i[i]] * pow(2, i - 1);
    }
    cout << score;

    return 0;
}