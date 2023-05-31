#include <iostream>
#include <vector>

using namespace std;

vector<vector<bool>> graph;
int N, M;

void input() {
    cin >> N >> M;
    graph.resize(N + 1, vector<bool>(N + 1, false));

    for (int i = 0; i < M; i++) {
        int l, h;
        cin >> l >> h;
        graph[l][h] = true;
    }
}

int solution() {
    for (int i = 1; i <= N; i++) {
        for (int l = 1; l <= N; l++) {
            for (int h = 1; h <= N; h++) {
                if (graph[l][i] && graph[i][h]) graph[l][h] = true;
            }
        }
    }

    int ret = 0;
    for (int i = 1; i <= N; i++) {
        bool flag = true;
        for (int j = 1; j <= N; j++) {
            if (i == j) continue;
            if (!graph[i][j] && !graph[j][i]) flag = false;
        }
        if (flag) ret++;
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    cout << solution();
    return 0;
}