#include <iostream>

using namespace std;

int dp[100005][2];
int arr[100005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    int max_res = 0x80000000;

    for (int i = 1; i <= N; i++) {
        dp[i][0] = max(arr[i], dp[i - 1][0] + arr[i]);

        if (i == 1) {
            dp[i][1] = arr[i];
        } else {
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + arr[i]);
        }
        max_res = max(max_res, max(dp[i][0], dp[i][1]));
    }

    cout << max_res;

    return 0;
}