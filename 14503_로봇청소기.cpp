#include <iostream>
#include <vector>

using namespace std;

struct Robot {
    int r, c, dir;
};

int N, M;
vector<vector<int> > map;
Robot robot;
int cnt;

// 상 좌 하 우
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, -1, 0, 1};

bool is_valid(int r, int c) { return r >= 0 && r < N && c >= 0 && c < M; }

int get_cleaned_num(Robot c) {
    // 현재 칸이 아직 청소되지 않은 경우, 현재 칸을 청소한다.
    if (map[c.r][c.c] == 0) {
        map[c.r][c.c] = 2;
        cnt++;
    }

    int ret = 0;

    bool is_all_clean = true;
    for (int i = 1; i <= 4; i++) {
        int t_dir = (c.dir + i) % 4;
        int tr = c.r + dr[t_dir];
        int tc = c.c + dc[t_dir];

        if (!is_valid(tr, tc)) continue;
        if (map[tr][tc] == 2 || map[tr][tc] == 1) continue;

        //  현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있는 경우
        Robot next = {tr, tc, t_dir};
        ret = get_cleaned_num(next);
        if (ret == -1) return -1;

        is_all_clean = false;
    }

    // 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 없는 경우

    // 어차피 다 방문하고 와서 is_all_clean은 필요 없다!!!
    if (is_all_clean) {
        int tr = c.r - dr[c.dir];
        int tc = c.c - dc[c.dir];

        if (map[tr][tc] == 1) {
            // 바라보는 방향의 뒤쪽 칸이 벽이라 후진할 수 없다면 작동을 멈춘다.
            // cout << cnt;
            // exit(0);
            return -1;
        }

        if (is_valid(tr, tc)) {
            Robot next = {tr, tc, c.dir};
            ret = get_cleaned_num(next);
            if (ret == -1) return -1;
        }
    }

    return ret;
}

void input() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    cin >> robot.r >> robot.c >> robot.dir;
    if (robot.dir == 1)
        robot.dir = 3;
    else if (robot.dir == 3)
        robot.dir = 1;
    map.resize(N, vector<int>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }
}

int main() {
    input();
    get_cleaned_num(robot);
    cout << cnt;
    return 0;
}