#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> dp;
vector<int> v;

int lb(int x) {
    int s = 0;
    int e = dp.size();
    int m;

    while (s < e) {
        m = (s + e) / 2;

        if (dp[m] < x) {
            s = m + 1;
        } else {
            e = m;
        }
    }
    return e;
}

void LIS(vector<int>& v) {
    for (auto x : v) {
        // auto idx = lb(x);
        // if (idx >= dp.size())
        //     dp.push_back(x);
        // else
        //     dp[idx] = x;
        auto it = lower_bound(dp.begin(), dp.end(), x);
        if (it == dp.end())
            dp.push_back(x);
        else
            *it = x;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    LIS(v);

    cout << dp.size();

    return 0;
}
