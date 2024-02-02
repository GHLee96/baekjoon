#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<int>> graph;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    graph.resize(N + 5, vector<int>(N + 5, 0x7fffff));

    for (int i = 0; i < M; i++) {

        int a, b;
        cin >> a >> b;

        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (graph[i][j] > graph[i][k] + graph[k][j]) {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }

    int min_val = 0x7fffffff;
    int res = 0;

    for (int i = 1; i <= N; i++) {
        int val = 0;
        for (int j = 1; j <= N; j++) {
            if (i == j)
                continue;
            val += graph[i][j];
        }

        if (min_val > val) {
            min_val = val;
            res = i;
        }
    }

    cout << res;
    return 0;
}