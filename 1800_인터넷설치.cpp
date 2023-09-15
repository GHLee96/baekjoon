/*
"비용이 X 이하인 케이블선들을 모두 고른 뒤에,
K 개 이하의 케이블선만으로
1 번 컴퓨터와 N번 컴퓨터까지 연결할 수 있다면,
총 비용은 X 이하일 것이다."
*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
    int to, cost;

    bool operator<(Node r) const { return cost > r.cost; }
};

int N, P, K; // K : 공짜 수
vector<vector<Node>> adj;
vector<int> dist;

void input() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> P >> K;

    adj.resize(N + 1);
    for (int i = 0; i < P; i++) {
        int from;
        int to;
        int cost;
        cin >> from >> to >> cost;
        adj[from].push_back({to, cost});
        adj[to].push_back({from, cost});
    }
}

bool dijkstra(int target) {
    priority_queue<Node> q;
    q.push({1, 0});

    dist.clear();
    dist.resize(N + 1, 0x7fffffff);

    dist[1] = 0;

    while (!q.empty()) {
        int now = q.top().to;
        int nowCost = q.top().cost;
        q.pop();

        if (dist[now] < nowCost)
            continue;

        for (int i = 0; i < adj[now].size(); i++) {
            int next = adj[now][i].to;
            int cost = adj[now][i].cost;

            int next_cost = dist[now] + (cost > target);
            if (dist[next] <= next_cost)
                continue;

            dist[next] = next_cost;
            q.push({next, dist[next]});
        }
    }

    return dist[N] <= K;
}

int main() {
    input();

    int l = 0;
    int r = 1000000 * 2;
    int res = -1;
    while (l <= r) {
        int mid = (l + r) / 2;

        if (dijkstra(mid)) {
            res = mid;
            r = mid - 1;

        } else {
            l = mid + 1;
        }
    }

    cout << res;

    return 0;
}