#include <iostream>
#include <vector>

using namespace std;

const int INF = 0xfffffff;
int n, m;
int cost_min[201][201];
int cost_max[201][201];

void input() {
    cin >> n;
    cin >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cost_min[i][j] = i == j ? 0 : INF;
            cost_max[i][j] = -1;
        }
    }

    for (int i = 0; i < m; i++) {
        int s, e, w;
        cin >> s >> e >> w;
        cost_min[s][e] = min(cost_min[s][e], w);
        cost_min[e][s] = min(cost_min[s][e], w);

        cost_max[s][e] = max(cost_max[s][e], w);
        cost_max[e][s] = max(cost_max[s][e], w);
    }
}

void solution() {
    for (int i = 1; i <= n; i++) {
        for (int s = 1; s <= n; s++) {
            for (int e = 1; e <= n; e++) {
                cost_min[s][e] =
                    min(cost_min[s][e], cost_min[s][i] + cost_min[i][e]);
            }
        }
    }

    float ignition = INF;
    for (int s = 1; s <= n; s++) {
        float max_len = 0;

        for (int i = 1; i <= n; i++) {
            for (int e = 1; e <= n; e++) {
                if (cost_max[i][e] == -1) continue;
                float ignit_len =

                    (cost_max[i][e] - (cost_min[s][e] - cost_min[s][i]));
                if (ignit_len > 0) {
                    // cout << "(" << s << i << e << ")"
                    //      << (ignit_len / 2) + (float)cost_min[s][e] << " ";
                    max_len = max(max_len, (ignit_len / 2) + cost_min[s][e]);
                }
            }
        }
        // cout << endl;
        ignition = min(ignition, max_len);
    }
    cout << fixed;
    cout.precision(1);
    cout << ignition;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    solution();
    return 0;
}
