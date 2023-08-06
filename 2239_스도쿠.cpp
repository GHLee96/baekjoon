#include <iostream>
#include <vector>

#define area(r, c) (r) / 3 * 3 + (c) / 3;

using namespace std;

const int N = 9;
vector<vector<int>> map;
vector<vector<int>> visit_r;
vector<vector<int>> visit_c;
vector<vector<int>> visit_area;

vector<vector<int>> res;
int sol(int r, int c) {
    if (r == N) {
        res = map;
        return 1;
    }

    if (map[r][c] != 0) {
        if (c + 1 == N) {
            if (sol(r + 1, 0)) return 1;
        } else {
            if (sol(r, c + 1)) return 1;
        }
        return 0;
    }

    for (int i = 1; i <= N; i++) {
        if (visit_r[r][i]) continue;
        if (visit_c[c][i]) continue;
        int area = area(r, c);
        if (visit_area[area][i]) continue;

        map[r][c] = i;
        visit_r[r][i] = 1;
        visit_c[c][i] = 1;
        visit_area[area][i] = 1;

        if (c + 1 == N) {
            if (sol(r + 1, 0)) return 1;
        } else {
            if (sol(r, c + 1)) return 1;
        }
        map[r][c] = 0;
        visit_r[r][i] = 0;
        visit_c[c][i] = 0;
        visit_area[area][i] = 0;
    }

    return 0;
}

int main() {
    map.resize(N, vector<int>(N));
    visit_r.resize(N, vector<int>(N + 1));
    visit_c.resize(N, vector<int>(N + 1));
    visit_area.resize(N, vector<int>(N + 1));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            scanf("%1d", &map[i][j]);
            // cin >> map[i][j];

            visit_r[i][map[i][j]] = 1;
            visit_c[j][map[i][j]] = 1;
            int area = area(i, j);
            visit_area[area][map[i][j]] = 1;
        }

    sol(0, 0);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d", res[i][j]);
        }
        printf("\n");
    }

    return 0;
}