#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int N, K, S;
int graph[405][405];

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

    cin >> S;
    for (int i = 1; i <= S; i++) {
        int a, b;
        cin >> a >> b;

        if (graph[a][b])
            cout << -1 << '\n';
        else if (graph[b][a])
            cout << 1 << '\n';
        else
            cout << 0 << '\n';
    }

    return 0;
}