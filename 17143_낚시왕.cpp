#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int R, C, M;

struct COORD {
    int r, c;
};

struct info_shark {
    COORD coord;
    int s, d, z;
};

vector<vector<int>> map;
vector<info_shark> shark;

bool cmp(info_shark &a, info_shark &b) { return a.z > b.z; }

void input() {
    cin >> R >> C >> M;
    shark.resize(M);
    map.resize(R + 1, vector<int>(C + 1, -1));

    for (int i = 0; i < M; i++) {
        int r, c;
        cin >> r >> c;
        shark[i].coord.r = r;
        shark[i].coord.c = c;
        cin >> shark[i].s >> shark[i].d >> shark[i].z;
    }
    sort(shark.begin(), shark.end(), cmp);

    for (int i = 0; i < M; i++) {
        map[shark[i].coord.r][shark[i].coord.c] = i;
    }
}

void move() {
    for (int i = 0; i < shark.size(); i++) {
        if (shark[i].coord.r != -1) {
            int next_r;
            int next_c;
            if (shark[i].d == 1) {
                int speed = shark[i].s - (shark[i].coord.r - 1);

                if (speed <= 0) {
                    next_r = 1 - speed;
                    next_c = shark[i].coord.c;

                    if (speed == 0) shark[i].d = 2;
                } else {
                    int q = speed / (R - 1);
                    int remain = speed % (R - 1);

                    if (q % 2 == 0) {
                        // 같은 방향
                        next_r = remain + 1;
                        next_c = shark[i].coord.c;
                        shark[i].d = 2;
                    } else {
                        // 반대 방향
                        next_r = R - remain;
                        next_c = shark[i].coord.c;
                    }
                }
            } else if (shark[i].d == 2) {
                int speed = shark[i].s - (R - shark[i].coord.r);
                if (speed <= 0) {
                    next_r = R + speed;
                    next_c = shark[i].coord.c;

                    if (speed == 0) shark[i].d = 1;
                } else {
                    int q = speed / (R - 1);
                    int remain = speed % (R - 1);

                    if (q % 2 == 1) {
                        // 같은 방향
                        next_r = remain + 1;
                        next_c = shark[i].coord.c;
                    } else {
                        // 반대 방향
                        next_r = R - remain;
                        next_c = shark[i].coord.c;
                        shark[i].d = 1;
                    }
                }
            } else if (shark[i].d == 3) {
                int speed = shark[i].s - (C - shark[i].coord.c);
                if (speed <= 0) {
                    next_r = shark[i].coord.r;
                    next_c = C + speed;

                    if (speed == 0) shark[i].d = 4;
                } else {
                    int q = speed / (C - 1);
                    int remain = speed % (C - 1);

                    if (q % 2 == 0) {
                        // 반대 방향
                        next_r = shark[i].coord.r;
                        next_c = C - remain;
                        shark[i].d = 4;
                    } else {
                        // 같은 방향
                        next_r = shark[i].coord.r;
                        next_c = remain + 1;
                    }
                }
            } else if (shark[i].d == 4) {
                int speed = shark[i].s - (shark[i].coord.c - 1);
                if (speed <= 0) {
                    next_r = shark[i].coord.r;
                    next_c = 1 - speed;

                    if (speed == 0) shark[i].d = 3;
                } else {
                    int q = speed / (C - 1);
                    int remain = speed % (C - 1);

                    if (q % 2 == 0) {
                        // 반대 방향
                        next_r = shark[i].coord.r;
                        next_c = remain + 1;
                        shark[i].d = 3;
                    } else {
                        // 같은 방향
                        next_r = shark[i].coord.r;
                        next_c = C - remain;
                    }
                }
            }

            shark[i].coord.r = next_r;
            shark[i].coord.c = next_c;
            if (map[next_r][next_c] != -1) {
                // 잡아먹힌다
                shark.erase(shark.begin() + i);
                i--;
            } else {
                map[next_r][next_c] = i;
            }
        }
    }
}

int cnt = 0;
void solution(int loc) {
    if (loc == C + 1) return;

    // 상어 잡기
    for (int r = 1; r <= R; r++) {
        if (map[r][loc] != -1) {
            // shark[map[r][loc]].coord = {-1, -1};  // init
            cnt += shark[map[r][loc]].z;
            shark.erase(shark.begin() + map[r][loc]);
            break;
        }
    }

    map.clear();
    map.resize(R + 1, vector<int>(C + 1, -1));

    // 상어 움직이기
    move();

    solution(loc + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    solution(1);
    cout << cnt;
    return 0;
}