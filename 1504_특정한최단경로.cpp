#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct info {
    int node;
    long long cost;
    int cnt;

    bool operator<(info r) const { return cost > r.cost; }
};

int N, E;
int v1, v2;

vector<info> adj[805];
vector<vector<long long>> dist;

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
    dist.resize(N + 5, vector<long long>(3, 0x7fffffffffff));

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
            if (next.node == v1 || next.node == v2 && next_cnt < 2)
                next_cnt++;

            if (dist[next.node][next_cnt] <=
                dist[now.node][now.cnt] + next.cost)
                continue;

            dist[next.node][next_cnt] = dist[now.node][now.cnt] + next.cost;

            q.push({next.node, dist[next.node][next_cnt], next_cnt});
        }
    }

    if (dist[N][2] == 0x7fffffffffff)
        cout << -1 << endl;
    else
        cout << dist[N][2] << endl;
}

int main() {
    input();
    sol();

    return 0;
}