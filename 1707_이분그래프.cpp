#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int V, E;
vector<vector<int>> graph;
vector<int> visit;

int bfs(int start) {

    queue<int> q;
    visit[start] = 1;
    q.push(start);

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        for (auto next : graph[now]) {
            if (visit[next]) {
                if (visit[now] == visit[next])
                    return -1;
                else
                    continue;
            }

            visit[next] = visit[now] == 1 ? 2 : 1;
            q.push(next);
        }
    }

    return 0;
}

void input() {
    cin >> V >> E;

    graph.clear();
    visit.clear();
    graph.resize(V + 1);
    visit.resize(V + 1);

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}

int sol() {
    for (int i = 1; i <= V; i++) {
        if (visit[i])
            continue;
        if (bfs(i) == -1)
            return -1;
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
        int ret = sol();

        if (ret == -1)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
    return 0;
}