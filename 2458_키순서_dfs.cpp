#include <iostream>
#include <vector>

using namespace std;

vector<vector<bool>> graph[2];
vector<bool> visit;
int N, M;

void input() {
    cin >> N >> M;
    graph[0].resize(N + 1, vector<bool>(N + 1, false));
    graph[1].resize(N + 1, vector<bool>(N + 1, false));

    for (int i = 0; i < M; i++) {
        int l, h;
        cin >> l >> h;
        graph[0][l][h] = true;
        graph[1][h][l] = true;
    }
}

int dfs(int v, int dir) {
    int cnt = 1;
    visit[v] = true;
    for (int i = 1; i <= N; i++) {
        if (v == i) continue;

        if (!visit[i] && graph[dir][v][i]) {
            cnt += dfs(i, dir);
        }
    }
    return cnt;
}

int solution() {
    int ret = 0;
    for (int i = 1; i <= N; i++) {
        int sum = 0;
        for (int dir = 0; dir <= 1; dir++) {
            visit.clear();
            visit.resize(N + 1, false);

            sum += dfs(i, dir) - 1;
        }

        if (sum >= N - 1) ret++;
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