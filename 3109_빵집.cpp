#include <iostream>

using namespace std;

int R, C;

bool map[10001][501] = {
    false,
};
bool visit[10001][501] = {
    false,
};

int dt[3][2] = {{-1, 1}, {0, 1}, {1, 1}};

int cnt = 0;

bool dfs(int r, int c) {
    visit[r][c] = true;
    if (c == C) {
        cnt++;
        return true;
    }

    for (auto t : dt) {
        int tr = r + t[0];
        int tc = c + t[1];

        if (tr >= 1 && tr <= R && tc >= 1 && tc <= C) {
            if (map[tr][tc] && !visit[tr][tc]) {
                if (dfs(tr, tc)) return true;
            }
        } else {
            continue;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> R >> C;

    char a;
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            cin >> a;
            if (a == '.')
                map[i][j] = true;
            else
                map[i][j] = false;
        }
    }

    for (int i = 1; i <= R; i++) {
        dfs(i, 1);
    }

    cout << cnt;

    return 0;
}