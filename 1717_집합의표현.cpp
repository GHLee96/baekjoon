#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

int get_parent(int idx) {
    if (parent[idx] == idx) return idx;
    return parent[idx] = get_parent(parent[idx]);
}

void set_union(int idx1, int idx2) {
    int p1 = get_parent(idx1);
    int p2 = get_parent(idx2);

    if (p1 == p2) return;

    if (p1 > p2)
        parent[p1] = p2;
    else
        parent[p2] = p1;
}

void solution(int i, int idx1, int idx2) {
    if (i == 0) {
        set_union(idx1, idx2);
    } else {
        if (get_parent(idx1) != get_parent(idx2))
            cout << "NO\n";
        else
            cout << "YES\n";
    }
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    int n, m;
    // cin >> n >> m;
    scanf("%d %d", &n, &m);

    parent.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    for (int j = 0; j < m; j++) {
        int i, idx1, idx2;
        // cin >> i >> idx1 >> idx2;
        scanf("%d %d %d", &i, &idx1, &idx2);
        solution(i, idx1, idx2);
    }

    return 0;
}