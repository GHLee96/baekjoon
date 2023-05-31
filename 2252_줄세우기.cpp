#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int N, M;
vector<int> degree;
vector<vector<int>> graph;
vector<int> ans;

void input() {
    cin >> N >> M;

    graph.resize(N + 1);
    degree.resize(N + 1);

    for (int i = 0; i < M; i++) {
        int s, e;
        cin >> s >> e;
        graph[s].push_back(e);
        degree[e]++;
    }
}

void solution() {
    queue<int> q;

    for (int i = 1; i <= N; i++) {
        if (degree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        ans.push_back(cur);

        for (int j = 0; j < graph[cur].size(); j++) {
            if (--degree[graph[cur][j]] == 0) q.push(graph[cur][j]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    solution();

    for (auto x : ans) cout << x << " ";
    return 0;
}