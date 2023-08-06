#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int n;
vector<int> v;

void LIS() {
    vector<int> res;

    for (int i = n - 1; i >= 0; i--) {
        int x = v[i];

        auto pos = lower_bound(res.begin(), res.end(), x);
        if (pos == res.end()) {
            res.push_back(x);
        } else {
            int idx = pos - res.begin();
            res[idx] = x;
        }
    }

    cout << res.size() << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    LIS();

    return 0;
}