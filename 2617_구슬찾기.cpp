#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int N, K, S;
int graph[105][105];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;

    for (int i = 0; i < K; i++) {
        int a, b;
        cin >> a >> b;

        graph[a][b] = 1;
    }

    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (graph[i][k] && graph[k][j]) {
                    graph[i][j] = 1;
                }
            }
        }
    }

    int res = 0;
    for (int i = 1; i <= N; i++) {
        int cnt1 = 0;
        int cnt2 = 0;

        for (int j = 1; j <= N; j++) {
            if (i == j)
                continue;

            if (graph[i][j])
                cnt1++;
            if (graph[j][i])
                cnt2++;
        }
        if (cnt1 > N / 2 || cnt2 > N / 2)
            res++;
    }

    cout << res << '\n';
    return 0;
}