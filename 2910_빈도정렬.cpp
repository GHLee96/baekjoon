#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int N, C;

struct info {
    int cnt, order;
};

unordered_map<int, info> m;

bool cmp(pair<int, info> a, pair<int, info> b) {
    if (a.second.cnt == b.second.cnt)
        return a.second.order < b.second.order;
    return a.second.cnt > b.second.cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> C;

    int order = 1;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;

        if (!m[a].cnt)
            m[a].order = order++;
        m[a].cnt++;
    }

    vector<pair<int, info>> v(m.begin(), m.end());

    sort(v.begin(), v.end(), cmp);

    for (auto x : v) {
        for (int i = 0; i < x.second.cnt; i++) {
            cout << x.first << ' ';
        }
    }

    return 0;
}