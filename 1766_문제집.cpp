#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int N, M;
vector<vector<int>> graph;
vector<int> ans;
vector<int> degree;

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
    priority_queue<int, vector<int>, greater<int>> q;

    for (int i = 1; i <= N; i++) {
        if (degree[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int cur = q.top();
        q.pop();

        ans.push_back(cur);

        for (int i = 0; i < graph[cur].size(); i++) {
            if (--degree[graph[cur][i]] == 0) q.push(graph[cur][i]);
        }
    }
}

int main() {
    input();
    solution();
    for (auto x : ans) {
        cout << x << " ";
    }
    return 0;
}