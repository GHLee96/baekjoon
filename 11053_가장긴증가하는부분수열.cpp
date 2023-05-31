#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    vector<int> dp;
    vector<int> v;
    cin >> n;
    v.resize(n);
    dp.resize(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (v[j] < v[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int answer = *max_element(dp.begin(), dp.end());
    cout << answer + 1 << endl;

    return 0;
}
