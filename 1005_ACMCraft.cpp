#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, K;
int T;
vector<int> t;
vector<vector<int>> graph;
vector<int> cost;
vector<int> degree;
int dest;

void input() {
    cin >> N >> K;

    t.clear();
    graph.clear();
    cost.clear();
    degree.clear();

    t.resize(N + 1);
    graph.resize(N + 1);
    cost.resize(N + 1);
    degree.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> t[i];
    }

    for (int i = 0; i < K; i++) {
        int s, e;
        cin >> s >> e;
        graph[s].push_back(e);
        degree[e]++;
    }

    cin >> dest;
}

int solution() {
    int ret = 0;
    queue<pair<int, int>> q;

    for (int i = 1; i <= N; i++) {
        if (degree[i] == 0) q.push({i, 0});
    }

    while (q.front().first != dest) {
        auto cur = q.front();
        q.pop();

        // cout << cur.first << " ";

        for (int i = 0; i < graph[cur.first].size(); i++) {
            if (cost[graph[cur.first][i]] < t[cur.first] + cur.second)
                cost[graph[cur.first][i]] = t[cur.first] + cur.second;

            if (--degree[graph[cur.first][i]] == 0)
                q.push({graph[cur.first][i], cost[graph[cur.first][i]]});
        }
    }

    return q.front().second + t[dest];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;

    for (int i = 0; i < T; i++) {
        input();
        cout << solution() << "\n";
    }

    return 0;
}