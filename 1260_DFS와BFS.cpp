#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M, V;
vector<vector<int>> adj;
bool visit[1001];

void dfs(int idx, int d) {
    if (d == N) {
        cout << '\n';
        return;
    }

    if (visit[idx]) return;
    visit[idx] = true;
    cout << idx << ' ';

    for (int i = 0; i < adj[idx].size(); i++) {
        int next = adj[idx][i];
        if (visit[next]) continue;
        dfs(next, d + 1);
    }
}

void bfs() {
    memset(visit, false, sizeof(bool) * (N + 1));

    queue<int> q;
    q.push(V);

    while (!q.empty()) {
        int c = q.front();
        q.pop();

        if (visit[c]) continue;
        visit[c] = true;

        cout << c << ' ';
        for (int i = 0; i < adj[c].size(); i++) {
            int next = adj[c][i];

            if (visit[next]) continue;
            q.push(next);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> V;

    adj.resize(N + 1);
    for (int i = 0; i < M; i++) {
        int s, e;
        cin >> s >> e;

        adj[s].push_back(e);
        adj[e].push_back(s);
    }

    for (int i = 0; i <= N; i++) {
        sort(adj[i].begin(), adj[i].end());
    }
    dfs(V, 0);
    cout << '\n';
    bfs();
    return 0;
}