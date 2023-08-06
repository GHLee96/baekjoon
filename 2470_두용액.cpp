#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    sort(v.begin(), v.end());

    int s = 0;
    int e = n - 1;

    int min_val = 0x7fffffff;
    pair<int, int> ans;
    while (s < e) {
        if (min_val > abs(v[s] + v[e])) {
            min_val = abs(v[s] + v[e]);
            ans = {v[s], v[e]};
        }

        if (v[s] + v[e] > 0) {
            e--;
        } else {
            s++;
        }
    }

    cout << ans.first << " " << ans.second;

    return 0;
}