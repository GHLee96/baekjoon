#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct info {
    int node;
    int cost;
    int cnt;

    bool operator<(info r) const { return cost > r.cost; }
};

int N, E;
int v1, v2;

vector<info> adj[805];
vector<vector<int>> dist;

void input() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> E;

    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        adj[a].push_back({b, c, 0});
        adj[b].push_back({a, c, 0});
    }

    cin >> v1 >> v2;
}

void sol() {
    dist.resize(N + 5, vector<int>(4, 0x7ffffff));

    priority_queue<info> q;
    q.push({1, 0, 0});
    dist[1][0] = 0;

    while (!q.empty()) {
        info now = q.top();
        q.pop();

        if (dist[now.node][now.cnt] < now.cost)
            continue;

        for (auto next : adj[now.node]) {

            int next_cnt = now.cnt;
            if (next.node == v1)
                next_cnt = now.cnt | 0x1;

            if (next.node == v2)
                next_cnt = now.cnt | 0x2;

            if (dist[next.node][next_cnt] <=
                dist[now.node][now.cnt] + next.cost)
                continue;

            dist[next.node][next_cnt] = dist[now.node][now.cnt] + next.cost;

            q.push({next.node, dist[next.node][next_cnt], next_cnt});
        }
    }

    if (dist[N][3] == 0x7ffffff)
        cout << -1 << endl;
    else
        cout << dist[N][3] << endl;
}

int main() {
    input();
    sol();

    return 0;
}