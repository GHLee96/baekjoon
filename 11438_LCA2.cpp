#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int N;
int depth[100005];
int parent[100005][17];  // log2(100005) = 16.xxx
vector<vector<int>> adj;

// 2^0일때의 parent, depth 설정
void dfs(int n) {
    for (auto x : adj[n]) {
        if (x == 1 || depth[x]) continue;  // 1 일때는 depth 0이므로 걸러준다

        parent[x][0] = n;
        depth[x] = depth[n] + 1;
        dfs(x);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    adj.resize(N + 1);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);

    // 2^k의 조상 세팅
    for (int k = 0; k < 17 - 1; k++) {
        for (int i = 1; i <= N; i++) {
            // 2^(k + 1)번째 조상 = 2^k번째 조상의 2^k번째 조상
            parent[i][k + 1] = parent[parent[i][k]][k];
        }
    }

    int M;
    cin >> M;

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;

        if (depth[u] < depth[v]) swap(u, v);

        int diff = depth[u] - depth[v];
        // 차이만큼 depth를 올려준다 (비트 연산 이용)
        // diff가 0될 때까지
        for (int j = 0; diff; j++) {
            if (diff % 2) u = parent[u][j];  // 비트만큼 점프

            diff = diff >> 1;  // 다음 비트 가져오기
        }

        if (u != v) {
            // 2^16번째 조상부터 탐색
            for (int k = 16; k >= 0; k--) {
                // parent가 존재하고, 서로 다르면
                if (parent[u][k] && parent[u][k] != parent[v][k]) {
                    // 다른 parent로 점프해서 그 사이를 탐색
                    u = parent[u][k];
                    v = parent[v][k];
                }
            }

            // u != v이면 바로 위 조상, u == v이면 자신이 답
            u = parent[u][0];
        }

        cout << u << '\n';
    }

    return 0;
}