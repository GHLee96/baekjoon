#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Edge {
    int cost, from, to;

    bool operator<(Edge b) const { return cost < b.cost; }
};

int V, E;

int parent[200001];
Edge edge[200001];
int res;
int all_sum;

int Find(int now) {
    if (parent[now] == now) return now;
    return parent[now] = Find(parent[now]);
}

void Union(int a, int b) {
    int root_a = Find(a);
    int root_b = Find(b);

    if (root_a == root_b) return;
    parent[root_a] = root_b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (1) {
        cin >> V >> E;

        if (V == 0 && E == 0) break;
        all_sum = 0;
        res = 0;
        for (int i = 0; i < E; i++) {
            cin >> edge[i].from >> edge[i].to >> edge[i].cost;
            all_sum += edge[i].cost;
        }

        sort(edge, edge + E);

        for (int i = 0; i < V; i++) {
            parent[i] = i;
        }

        for (int i = 0; i < E; i++) {
            if (Find(edge[i].from) == Find(edge[i].to)) continue;
            Union(edge[i].from, edge[i].to);
            res += edge[i].cost;
        }

        cout << all_sum - res << '\n';
    }
    return 0;
}
