#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M;
int start, dest;
vector<vector<pair<int, int>>> adj;
vector<int> dist;

int get_min_cost() {
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        q;
    int min_cost = 0;
    q.push({0, start});

    dist.resize(N + 1, 0x7fffffff);
    dist[start] = 0;

    while (!q.empty()) {
        int current_d = q.top().first;
        int c = q.top().second;

        q.pop();

        if (dist[c] < current_d) continue;

        if (c == dest) {
            min_cost = current_d;
            break;
        }
        for (int i = 0; i < adj[c].size(); i++) {
            int d = adj[c][i].first;
            int next = adj[c][i].second;

            if (dist[next] > current_d + d) {
                dist[next] = current_d + d;
                q.push({current_d + d, next});
            }
        }
    }
    return min_cost;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;

    adj.resize(N + 1);
    for (int i = 0; i < M; i++) {
        int s, e, cost;
        cin >> s >> e >> cost;
        adj[s].push_back({cost, e});
    }
    cin >> start >> dest;

    cout << get_min_cost();

    return 0;
}