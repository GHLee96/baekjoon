#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, V, E;
int A, B;

struct info {
    int n, cost;

    bool operator<(info b) const { return cost > b.cost; }
};

vector<vector<info>> adj;
vector<int> dist;
vector<int> home;

int sol(int start) {
    dist.clear();
    dist.resize(V + 1, 0x7fffffff);

    priority_queue<info> q;
    dist[start] = 0;
    q.push({start, 0});

    while (!q.empty()) {
        info now = q.top();
        q.pop();

        for (auto next : adj[now.n]) {
            if (dist[next.n] <= dist[now.n] + next.cost)
                continue;

            dist[next.n] = dist[now.n] + next.cost;
            q.push({next.n, dist[next.n]});
        }
    }

    int res = 0;
    for (auto k : home) {
        if (dist[k] == 0x7fffffff)
            res -= 1;
        else
            res += dist[k];
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> V >> E;

    cin >> A >> B;

    home.resize(N);
    adj.resize(V + 1);

    for (int i = 0; i < N; i++) {
        cin >> home[i];
    }

    for (int i = 0; i < E; i++) {
        int a, b, cost;
        cin >> a >> b >> cost;

        adj[a].push_back({b, cost});
        adj[b].push_back({a, cost});
    }

    int kist = sol(A);
    int food = sol(B);

    cout << kist + food << endl;

    return 0;
}