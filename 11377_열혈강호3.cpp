#include <iostream>
#include <vector>

using namespace std;

int n, m, k;

vector<vector<int>> adj;
vector<int> matched;
vector<bool> visited;

bool dfs(int u) {
    for (int v : adj[u]) {
        if (visited[v]) continue;
        visited[v] = true;

        if (matched[v] == -1 || dfs(matched[v])) {
            matched[v] = u;
            return true;
        }
    }

    return false;
}

int bit_matching(int n, int m, int k) {
    int match = 0;
    int double_match = 0;
    matched.assign(m + 1, -1);

    for (int u = 1; u <= n; u++) {
        visited.assign(m + 1, false);
        if (dfs(u)) match++;
    }

    for (int u = 1; u <= n; u++) {
        visited.assign(m + 1, false);
        if (dfs(u)) double_match++;
        if (double_match == k) break;
    }

    match += double_match;
    return match;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;

    adj.resize(n + 1);

    for (int i = 1; i <= n; i++) {
        int n_work;
        cin >> n_work;
        for (int j = 0; j < n_work; j++) {
            int v;
            cin >> v;
            adj[i].push_back(v);
        }
    }

    cout << bit_matching(n, m, k);

    return 0;
}
