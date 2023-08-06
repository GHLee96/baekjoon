#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> dp(n);

    for (int i = 0; i < n; i++) cin >> arr[i];

    for (int i = 0; i < n; i++) {
        dp[i] = arr[i];
        for (int j = 0; j < i; j++) {
            int sum = dp[j];
            if (arr[i] > arr[j]) {
                sum += arr[i];
                dp[i] = max(dp[i], sum);
            }
        }
    }

    int res = 0;
    for (int i = 0; i < dp.size(); i++) {
        res = max(res, dp[i]);
    }

    cout << res;
    return 0;
}