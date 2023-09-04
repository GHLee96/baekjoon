#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int R, C;

struct coord {
    int r, c, cost;
};

struct Edge {
    int to, cost;

    bool operator<(Edge b) const { return cost > b.cost; }
};

int parent[252];
char map[51][51];
int K;

vector<coord> A;

int cost[252][252];

int table[51][51];
int visit[51][51];

int dr[4] = {0, 0, -1, 1};
int dc[4] = {1, -1, 0, 0};

vector<vector<Edge>> v;

bool is_valid(coord a) { return a.r >= 0 && a.r < R && a.c >= 0 && a.c < C; }

int Find(int now) {
    if (parent[now] == now) return now;
    return parent[now] = Find(parent[now]);
}

void Union(int a, int b) {
    int root_a = Find(a);
    int root_b = Find(b);

    if (root_a == root_b) return;
    parent[root_b] = root_a;
}

int bfs(coord start) {
    queue<coord> q;
    q.push(start);
    visit[start.r][start.c] = 1;

    while (!q.empty()) {
        coord now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = now.r + dr[i];
            int nc = now.c + dc[i];

            if (!is_valid({nr, nc})) continue;
            if (map[nr][nc] == '1') continue;
            if (visit[nr][nc]) continue;
            visit[nr][nc] = 1;

            q.push({nr, nc, now.cost + 1});

            if (!table[nr][nc]) continue;
            v[table[start.r][start.c]].push_back({table[nr][nc], now.cost + 1});
            v[table[nr][nc]].push_back({table[start.r][start.c], now.cost + 1});
        }
    }
    return 0;
}

void prim() {
    priority_queue<Edge> q;

    int visit[252] = {
        0,
    };
    vector<int> dist(252, 0x7fffffff);
    visit[1] = 1;

    for (int i = 0; i < v[1].size(); i++) {
        q.push(v[1][i]);
    }

    int sum = 0;
    int cnt = 0;

    while (!q.empty()) {
        Edge now = q.top();
        q.pop();

        if (visit[now.to]) continue;
        visit[now.to] = 1;
        sum += now.cost;
        cnt++;

        for (int i = 0; i < v[now.to].size(); i++) {
            if (dist[v[now.to][i].to] < v[now.to][i].cost) continue;
            q.push(v[now.to][i]);
        }
    }

    if (cnt != K)
        cout << -1;
    else
        cout << sum << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> R >> K;
    C = R;

    A.clear();
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> map[i][j];

            if (map[i][j] == 'S' || map[i][j] == 'K') {
                A.push_back({i, j});
                table[i][j] = A.size();
                parent[A.size()] = A.size();
            }
        }
    }

    v.clear();
    v.resize(A.size() + 1);

    int res = 0;
    for (int i = 1; i < A.size(); i++) {
        bfs(A[i]);
        memset(visit, 0, sizeof(visit));
    }

    prim();

    return 0;
}