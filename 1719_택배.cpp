#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n;
    cin >> m;

    v.resize(n + 1, vector<int>(n + 1, 0xfffffff));

    for (int i = 0; i < m; i++) {
        int s, e, w;
        cin >> s >> e >> w;
        v[s][e] = w;
        v[e][s] = w;
    }

    for (int i = 1; i <= n; i++) {
        for (int s = 1; s <= n; s++) {
            for (int e = 1; e <= n; e++) {
                if (s == e || i == s || i == e) continue;
                if (v[s][e] > v[s][i] + v[i][e]) {
                    v[s][e] = v[s][i] + v[i][e];
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (v[i][j] == 0xfffffff)
                cout << "0 ";
            else
                cout << v[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}