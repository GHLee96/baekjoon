#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

struct Edge {
    int to, cost;

    bool operator<(Edge b) const { return cost > b.cost; }
};

int N, M;
int K;
vector<vector<Edge>> adj;

vector<int> dist;
vector<int> pre;

int target_from;
int target_to;

void dijkstra(int start, int destination, int mode) {
    priority_queue<Edge> pq;
    pq.push({start, 0});
    dist[start] = 0;

    while (!pq.empty()) {
        int now = pq.top().to;
        int cost = pq.top().cost;
        pq.pop();

        if (cost > dist[now]) continue;

        for (int i = 0; i < adj[now].size(); i++) {
            Edge next = adj[now][i];

            if (dist[next.to] <= next.cost + cost) continue;

            if (mode == 1) {
                if ((now == target_from && next.to == target_to) ||
                    (now == target_to && next.to == target_from))
                    continue;
            }

            if (mode == 0) {
                pre[next.to] = now;
            }

            dist[next.to] = next.cost + cost;

            pq.push({next.to, dist[next.to]});
        }
    }
}

int max_dist = 0;

void remove(int now) {
    // for (auto next : pre[now]) {

    while (1) {
        int next = pre[now];

        target_from = next;
        target_to = now;

        dist.clear();
        dist.resize(N + 1, 0x7fffffff);

        dijkstra(1, N, 1);

        max_dist = max(max_dist, dist[N]);

        now = next;
        if (now == 1) break;
    }
}

void input() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    adj.resize(N + 1);
    dist.resize(N + 1, 0x7fffffff);
    pre.resize(N + 1);

    for (int i = 0; i < M; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;

        adj[from].push_back({to, cost});
        adj[to].push_back({from, cost});
    }
}

int main() {
    input();
    dijkstra(1, N, 0);
    remove(N);
    cout << max_dist;
    return 0;
}