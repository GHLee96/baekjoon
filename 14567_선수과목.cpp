// #define TOPOLOGICAL
#define DP

#ifdef TOPOLOGICAL

#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M;

vector<int> adj[1005];
int indegree[1005];
int res[1005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int s, e;
        cin >> s >> e;

        adj[s].push_back(e);
        indegree[e]++;
    }

    queue<int> q;

    for (int i = 1; i <= N; i++) {
        if (indegree[i] == 0) {
            q.push(i);
            res[i] = 1;
        }
    }

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        for (auto next : adj[now]) {
            res[next] = max(res[next], res[now] + 1);
            if (--indegree[next] == 0) {
                q.push(next);
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << res[i] << ' ';
    }

    return 0;
}

#endif

#ifdef DP

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> adj[1005];
int dp[1005];

int sol(int num) {
    if (adj[num].size() == 0)
        return 1;
    int &ret = dp[num];
    if (ret != 0)
        return ret;

    ret = 1;
    for (auto next : adj[num]) {
        ret = max(ret, sol(next) + 1);
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        adj[t2].push_back(t1);
    }

    for (int i = 1; i <= N; i++) {
        cout << sol(i) << ' ';
    }
    cout << endl;
}
#endif