#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) {
        return a.second < b.second ? 1 : 0;
    }
    return a.first < b.first;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, L;
    cin >> N >> L;
    vector<pair<int, int>> hole;

    for (int i = 0; i < N; i++) {
        int s, e;
        cin >> s >> e;
        hole.push_back({s, e - 1});
    }
    sort(hole.begin(), hole.end(), cmp);

    int res = 0;
    int mem = 0;
    int size = hole.size();
    for (int i = 0; i < size; i++) {
        int s = hole[i].first;
        int e = hole[i].second;

        if (s > mem) mem = s;

        while (mem <= e) {
            mem += L;
            res++;
        }
        // res += (e - s + 1) / L;
        // if ((e - s + 1) % L != 0) {
        //     res++;
        //     mem = s + L * ((e - s + 1) / L + 1) - 1;
        // }
    }
    cout << res;

    return 0;
}