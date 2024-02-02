#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    v.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    cin >> M;
    for (int i = 0; i < M; i++) {
        int a;
        cin >> a;

        auto r = upper_bound(v.begin(), v.end(), a);
        auto l = lower_bound(v.begin(), v.end(), a);

        cout << (int)(r - l) << ' ';
    }

    return 0;
}