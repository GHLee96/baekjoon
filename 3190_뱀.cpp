#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Snake {
    int r, c, dir;
};

int N;
int n;

vector<vector<int> > map;

Snake snake;
Snake snake_tail;

queue<pair<int, int> > move_dir;
queue<Snake> q_snake;
int cnt;

// 상 좌 하 우
int dr[] = {0, -1, 0, 1};
int dc[] = {1, 0, -1, 0};

bool is_valid(int r, int c) { return r >= 0 && r < N && c >= 0 && c < N; }

// 0 : 빈 공간, 1 : 사과, 2 : 뱀

int t = 0;

int get_end_time(Snake c) {
    int ret = 0;

    int i = 0;
    if (!move_dir.empty() && t == move_dir.front().first) {
        i = move_dir.front().second;
        move_dir.pop();
    }

    int t_dir = (c.dir + i);
    if (t_dir > 3)
        t_dir -= 4;
    else if (t_dir < 0)
        t_dir += 4;

    int tr = c.r + dr[t_dir];
    int tc = c.c + dc[t_dir];

    snake_tail = q_snake.front();

    if (!is_valid(tr, tc)) return -1;

    if (map[tr][tc] == 0) {
        // 빈 공간
        map[tr][tc] = 2;
        q_snake.push({tr, tc, t_dir});

        map[snake_tail.r][snake_tail.c] = 0;
        q_snake.pop();
    } else if (map[tr][tc] == 1) {
        // 사과
        map[tr][tc] = 2;
        q_snake.push({tr, tc, t_dir});
    } else if (map[tr][tc] == 2) {
        // 뱀
        return -1;
    }

    //  현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있는 경우
    Snake next = {tr, tc, t_dir};
    t++;
    ret = get_end_time(next);
    if (ret == -1) return -1;

    return ret;
}

void input() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    cin >> n;

    map.resize(N, vector<int>(N));
    for (int i = 0; i < n; i++) {
        int r, c;
        cin >> r >> c;
        map[r - 1][c - 1] = 1;
    }

    cin >> n;
    for (int i = 0; i < n; i++) {
        int time;
        char c_dir;
        int dir;
        cin >> time >> c_dir;

        if (c_dir == 'D')
            dir = -1;
        else
            dir = 1;

        move_dir.push({time, dir});
    }

    snake = {0, 0, 0};
    q_snake.push(snake);
}

int main() {
    input();
    get_end_time(snake);
    cout << t + 1;
    return 0;
}