#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#define psi pair<string, int>

using namespace std;

int N, M;
unordered_map<string, int> m;

bool cmp(psi a, psi b) {
    if (a.second == b.second) {
        if (a.first.size() == b.first.size()) {
            return a.first < b.first;
        }

        return a.first.size() > b.first.size();
    }

    return a.second > b.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;

        if (s.size() < M)
            continue;
        m[s]++;
    }

    vector<psi> arr(m.begin(), m.end());
    sort(arr.begin(), arr.end(), cmp);

    for (auto x : arr) {
        cout << x.first << '\n';
    }
    return 0;
}