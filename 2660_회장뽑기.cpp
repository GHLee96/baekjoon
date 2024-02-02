#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<int>> graph;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    graph.resize(N + 5, vector<int>(N + 5, 0x7fffff));

    while (1) {
        int a, b;
        cin >> a >> b;

        if (a == -1 && b == -1)
            break;
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

    int total_min = 0x7fffffff;
    vector<int> candidate;

    for (int i = 1; i <= N; i++) {
        int max_val = 0;
        for (int j = 1; j <= N; j++) {
            if (i == j)
                continue;
            max_val = max(graph[i][j], max_val);
        }

        if (max_val < total_min) {
            candidate.clear();
            candidate.push_back(i);
            total_min = max_val;
        } else if (max_val == total_min) {
            candidate.push_back(i);
        }
    }

    cout << total_min << ' ' << candidate.size() << '\n';
    for (auto x : candidate)
        cout << x << ' ';
    return 0;
}