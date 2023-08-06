#include <algorithm>
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

    for (int u = 0; u < n; u++) {
        visit.clear();
        visit.resize(m + 1, false);

        if (dfs(u)) match++;
    }

    return match;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;

    cin >> n >> m;
    adj.resize(n);
    visit.resize(m + 1);
    matched.resize(m + 1, -1);
    for (int i = 0; i < n; i++) {
        int n_cage;
        cin >> n_cage;
        for (int j = 0; j < n_cage; j++) {
            int cage;
            cin >> cage;
            adj[i].push_back(cage);
        }
    }

    cout << bi_matching(n, m);

    return 0;
}