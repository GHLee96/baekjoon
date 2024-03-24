#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct coord {
    int x, y;
};

coord home, dest;
coord store[105];
int visit[105];

int n;

vector<int> graph[105];

int get_dist(coord a, coord b) { return abs(a.x - b.x) + abs(a.y - b.y); }

void input() {
    cin >> n;

    cin >> home.x >> home.y;

    for (int i = 1; i <= n; i++) {
        cin >> store[i].x >> store[i].y;
    }
    cin >> dest.x >> dest.y;

    // store 앞, 뒤로 출발, 도착 지점 추가
    store[0].x = home.x;
    store[0].y = home.y;
    store[n + 1].x = dest.x;
    store[n + 1].y = dest.y;

    // 초기화
    memset(visit, 0, sizeof(visit));
    for (int i = 0; i < 105; i++)
        graph[i].clear();
}

int sol() {
    // 각 지점에서 갈 수 있는 곳 체크
    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < n + 2; j++) {
            if (get_dist(store[i], store[j]) <= 1000) {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }

    // bfs로 갈 수 있는 곳 가기
    queue<int> q;
    q.push(0);
    visit[0] = 1;

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        for (auto next : graph[now]) {
            if (visit[next])
                continue;
            visit[next] = 1;

            if (next == n + 1)
                return 1;
            q.push(next);
        }
    }

    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        input();
        if (sol())
            cout << "happy" << '\n';
        else
            cout << "sad" << '\n';
    }

    return 0;
}