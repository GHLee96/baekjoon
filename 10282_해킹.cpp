#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct info {
    int num, cost;

    bool operator<(info b) const { return cost > b.cost; }
};

vector<vector<info>> graph;
vector<int> dist;

int N, D, C;

void input() {

    cin >> N >> D >> C;

    graph.clear();
    graph.resize(N + 1);

    dist.clear();
    dist.resize(N + 1, 0x7fffffff);

    for (int i = 0; i < D; i++) {
        int a, b, s;
        cin >> a >> b >> s;

        graph[b].push_back({a, s});
    }
}

void sol() {
    priority_queue<info> q;
    q.push({C, 0});
    dist[C] = 0;

    while (!q.empty()) {
        info now = q.top();
        q.pop();

        if (dist[now.num] < now.cost)
            continue;

        for (auto x : graph[now.num]) {

            if (dist[x.num] > now.cost + x.cost) {
                dist[x.num] = now.cost + x.cost;
                q.push({x.num, dist[x.num]});
            }
        }
    }

    int infected_num = 0;
    int total_num = 0;
    int last_num = C;
    for (int i = 1; i <= N; i++) {
        if (dist[i] != 0x7fffffff) {
            if (dist[i] > dist[last_num]) {
                last_num = i;
            }
            infected_num++;
        }
    }

    cout << infected_num << ' ' << dist[last_num] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        input();
        sol();
    }

    return 0;
}