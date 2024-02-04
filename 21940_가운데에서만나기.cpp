#include <iostream>
#include <vector>

using namespace std;

int N, M, K;

vector<vector<int>> adj;
vector<int> start;

void input() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    adj.resize(N + 5, vector<int>(N + 5, 0x7ffffff));

    for (int i = 0; i < M; i++) {
        int s, e, c;
        cin >> s >> e >> c;

        adj[s][e] = c;
    }

    cin >> K;

    for (int i = 0; i < K; i++) {
        int n;
        cin >> n;
        start.push_back(n);
    }
}

int main() {
    input();

    for (int i = 1; i <= N; i++)
        adj[i][i] = 0;

    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }

    int res = 0x7fffffff;
    vector<int> city;
    for (int i = 1; i <= N; i++) {
        int sum = 0;
        for (auto x : start) {
            int s = 0;
            s += adj[x][i];
            s += adj[i][x];
            sum = max(sum, s);
        }

        if (res > sum) {
            res = sum;
            city.clear();
            city.push_back(i);
        } else if (res == sum) {
            city.push_back(i);
        }
    }

    for (auto x : city) {
        cout << x << ' ';
    }

    return 0;
}