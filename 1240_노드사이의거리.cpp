#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

struct node {
    int n, cost;
};

int N, M;
// vector<node> adj[1005];
vector<vector<int>> dist(1005, vector<int>(1005, 0x7ffffff));

void input() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N - 1; i++) {
        int a, b, cost;
        cin >> a >> b >> cost;

        dist[a][b] = cost;
        dist[b][a] = cost;
    }

    for (int i = 1; i <= N; i++) {
        dist[i][i] = 0;
    }
}

int main() {
    input();

    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        cout << dist[a][b] << '\n';
    }

    return 0;
}