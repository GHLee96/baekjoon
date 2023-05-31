#include <iostream>
#include <vector>

using namespace std;

const int INF = 0xfffffff;
int n, m;
int cost[101][101];
vector<int> route[101][101];

void input() {
    cin >> n;
    cin >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cost[i][j] = i == j ? 0 : INF;
        }
    }

    for (int i = 0; i < m; i++) {
        int s, e, w;
        cin >> s >> e >> w;
        cost[s][e] = min(cost[s][e], w);
    }
}

void solution() {
    for (int i = 1; i <= n; i++) {
        for (int s = 1; s <= n; s++) {
            for (int e = 1; e <= n; e++) {
                if (cost[s][e] > cost[s][i] + cost[i][e]) {
                    cost[s][e] = cost[s][i] + cost[i][e];
                    route[s][e].clear();
                    for (int j = 0; j < route[s][i].size(); j++)
                        route[s][e].push_back(route[s][i][j]);

                    route[s][e].push_back(i);

                    for (int j = 0; j < route[i][e].size(); j++)
                        route[s][e].push_back(route[i][e][j]);
                }
            }
        }
    }
}

void print() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (cost[i][j] == INF)
                cout << "0 ";
            else
                cout << cost[i][j] << " ";
        }
        cout << "\n";
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int size = cost[i][j] == 0 || cost[i][j] == INF
                           ? route[i][j].size()
                           : route[i][j].size() + 2;
            cout << size << " ";
            if (size) cout << i << " ";
            for (int k = 0; k < route[i][j].size(); k++)
                cout << route[i][j][k] << " ";
            if (size) cout << j << " ";
            cout << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    solution();
    print();
    return 0;
}