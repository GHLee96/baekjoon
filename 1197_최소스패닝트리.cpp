#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct info {
    int s, e, w;
};

info map[100001];
int check[10001];

bool cmp(const info& a, const info& b) { return a.w < b.w; }

int get_parent(int node) {
    if (check[node] == node) return node;
    return get_parent(check[node]);
}

void union_parent(int node_a, int node_b) {
    int parent_a = get_parent(node_a);
    int parent_b = get_parent(node_b);
    if (parent_a < parent_b)
        check[parent_b] = parent_a;
    else
        check[parent_a] = parent_b;
}

bool is_cycle(int node_a, int node_b) {
    if (get_parent(node_a) == get_parent(node_b)) return true;
    return false;
}

int main() {
    int V, E, sum = 0;
    cin >> V >> E;

    for (int i = 0; i < E; i++) {
        cin >> map[i].s >> map[i].e >> map[i].w;
    }

    for (int i = 1; i <= V; i++) {
        check[i] = i;
    }

    sort(map, map + E, cmp);

    for (int i = 0; i < E; i++) {
        if (!is_cycle(map[i].s, map[i].e)) {
            sum += map[i].w;
            union_parent(map[i].s, map[i].e);
        }
    }

    cout << sum;

    return 0;
}