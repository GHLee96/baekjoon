#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> v;
vector<vector<int>> res;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n;
    cin >> m;

    v.resize(n + 1, vector<int>(n + 1, 0xfffffff));
    res.resize(n + 1, vector<int>(n + 1));
    for (int i = 0; i < m; i++) {
        int s, e, w;
        cin >> s >> e >> w;
        v[s][e] = w;
        v[e][s] = w;
        res[s][e] = e;
        res[e][s] = s;
    }

    for (int i = 1; i <= n; i++) {
        v[i][i] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int s = 1; s <= n; s++) {
            for (int e = 1; e <= n; e++) {
                if (v[s][e] > v[s][i] + v[i][e]) {
                    v[s][e] = v[s][i] + v[i][e];
                    res[s][e] = res[s][i];
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (!res[i][j]) {
                cout << '-' << ' ';
            } else {
                cout << res[i][j] << ' ';
            }
        }
        cout << '\n';
    }

    return 0;
}