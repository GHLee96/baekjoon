#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;

vector<vector<int>> map;
vector<int> cnt;
vector<int> res;

int sol() {
    queue<int> q;

    for (int i = 1; i <= N; i++) {
        if (cnt[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int c = q.front();
        q.pop();

        res.push_back(c);
        for (int i = 0; i < map[c].size(); i++) {
            int next = map[c][i];
            if (--cnt[next] == 0) {
                q.push(next);
            }
        }
    }

    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    cin >> M;

    int n;
    int singer;
    map.resize(N + 1);
    cnt.resize(N + 1);
    for (int i = 0; i < M; i++) {
        cin >> n;
        vector<int> v(n);
        for (int j = 0; j < n; j++) cin >> v[j];
        for (int j = 0; j < n - 1; j++) {
            map[v[j]].push_back(v[j + 1]);
            cnt[v[j + 1]]++;
        }
    }
    sol();

    if (res.size() != N)
        cout << "0\n";
    else
        for (auto x : res) cout << x << "\n";

    return 0;
}