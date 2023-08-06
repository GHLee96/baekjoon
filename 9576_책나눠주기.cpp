#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<bool> visit;
vector<int> matched;

bool dfs(int u) {
    for (auto v : adj[u]) {
        if (visit[v]) continue;
        visit[v] = true;

        if (matched[v] == -1 || dfs(matched[v])) {
            matched[v] = u;
            return true;
        }
    }

    return false;
}

int bi_matching(int n, int m) {
    int match = 0;

    for (int i = 0; i < n; i++) {
        visit.assign(m, false);

        if (dfs(i)) match++;
    }

    return match;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    int n, m;

    cin >> T;
    for (int test_case = 1; test_case <= T; test_case++) {
        cin >> n >> m;

        adj.clear();
        adj.resize(m);
        matched.assign(n + 1, -1);
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;

            for (int k = a; k <= b; k++) adj[i].push_back(k);
        }
        cout << bi_matching(m, n) << "\n";
    }

    return 0;
}