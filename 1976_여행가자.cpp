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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    parent.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int is_connect;
            cin >> is_connect;

            if (is_connect) {
                set_union(i, j);
            }
        }
    }

    int p;
    for (int i = 0; i < m; i++) {
        int city;
        cin >> city;
        if (i == 0) {
            p = get_parent(city);
            continue;
        }

        if (p != get_parent(city)) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";

    return 0;
}