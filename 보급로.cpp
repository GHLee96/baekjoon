#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef struct info {
    int r, c, dis;  // row, column, 출발지부터의 시간
} info;

int dr[4] = {0, 0, -1, 1};
int dc[4] = {-1, 1, 0, 0};

int N;
vector<vector<int>> arr;  // 복구 시간 정보
vector<vector<int>> dis;  // 출발지부터의 최단 시간

bool is_map(int r, int c) { return (r >= 0 && r < N && c >= 0 && c < N); }

// priority queue distance 기준으로 오름차순 정렬
struct cmp {
    bool operator()(const info& a, const info& b) { return a.dis > b.dis; }
};

int bfs() {
    int min_time = 0;
    priority_queue<info, vector<info>, cmp> q;
    q.push({0, 0, 0});

    while (!q.empty()) {
        info current = q.top();
        q.pop();

        if (dis[current.r][current.c] < current.dis) continue;

        // 도착지에 도착
        if (current.r == N - 1 && current.c == N - 1) {
            min_time = current.dis;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int tr = current.r + dr[i];
            int tc = current.c + dc[i];

            if (!is_map(tr, tc)) continue;

            if (dis[tr][tc] > current.dis + arr[tr][tc]) {
                dis[tr][tc] = current.dis + arr[tr][tc];
                q.push({tr, tc, current.dis + arr[tr][tc]});
            }
        }
    }

    return min_time;
}

int main() {
    int T;
    int test_case;

    // freopen("input (1).txt", "r", stdin);

    scanf("%d", &T);
    for (test_case = 1; test_case <= T; test_case++) {
        scanf("%d", &N);

        arr.clear();
        dis.clear();
        arr.resize(N, vector<int>(N));
        dis.resize(N, vector<int>(N, 0x7fffffff));

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                scanf("%1d", &arr[i][j]);
            }
        }

        int min_time = bfs();
        printf("#%d %d\n", test_case, min_time);
    }

    return 0;
}