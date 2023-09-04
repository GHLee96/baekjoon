#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int parent;
    vector<int> child;
};

Node node[50001];
int N, M;
int t1, t2;

int level[50001];
vector<int> adj[50001];

void level_matching() {
    if (level[t1] < level[t2]) {
        while (level[t1] != level[t2]) {
            t2 = node[t2].parent;
        }
    } else if (level[t1] > level[t2]) {
        while (level[t1] != level[t2]) {
            t1 = node[t1].parent;
        }
    }
}

void dfs(int now, int l) {
    if (now == 0) return;

    level[now] = l;

    for (auto next : adj[now]) {
        if (level[next]) continue;

        node[next].parent = now;
        dfs(next, l + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    memset(node, 0, sizeof(node));
    memset(level, 0, sizeof(level));

    for (int i = 0; i < N - 1; i++) {
        int parent, child;
        cin >> parent >> child;

        adj[parent].push_back(child);
        adj[child].push_back(parent);
    }

    dfs(1, 1);

    cin >> M;

    for (int i = 0; i < M; i++) {
        cin >> t1 >> t2;
        level_matching();

        while (t1 != t2) {
            t2 = node[t2].parent;
            t1 = node[t1].parent;
        }

        cout << t1 << '\n';
    }

    return 0;
}