#include <iostream>

using namespace std;

int N, M, T;

int hudle[305][305];

void input() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> T;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            hudle[i][j] = 0x7ffffff;
        }
    }

    for (int i = 0; i < M; i++) {
        int u, v, h;
        cin >> u >> v >> h;

        hudle[u][v] = h;
    }
}

void floyd() {
    // 모든 정점들 간의 높이가 높은 허들의 높이가 최소인 값을 찾는다
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                // 가장 높은 허들의 최소
                hudle[i][j] = min(hudle[i][j], max(hudle[i][k], hudle[k][j]));
            }
        }
    }
}

int main() {
    input();
    floyd();

    for (int tc = 1; tc <= T; tc++) {
        int s, e;
        cin >> s >> e;

        if (hudle[s][e] == 0x7ffffff)
            cout << -1 << '\n';
        else
            cout << hudle[s][e] << '\n';
    }

    return 0;
}