#include <iostream>
#include <vector>

using namespace std;

int N, M;
int parent[500001];

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
    cin >> N >> M;

    for (int i = 0; i <= N; i++) {
        parent[i] = i;
    }

    for (int i = 1; i <= M; i++) {
        int a, b;
        cin >> a >> b;

        if (Find(a) == Find(b)) {
            cout << i;
            return 0;
        }
        Union(a, b);
    }

    cout << 0;

    return 0;
}