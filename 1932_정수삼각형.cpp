#include <iostream>
#include <vector>

using namespace std;

const int MAX_SIZE = 500 * 501 / 2 + 1;
int arr[MAX_SIZE];
int dp[MAX_SIZE];
int n;
int max_res = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n * (n + 1) / 2; i++) {
        cin >> arr[i];
    }

    int offset = 1;
    int cnt = 0;
    dp[1] = arr[1];
    for (int i = 1; i <= n * (n + 1) / 2 - n; i++) {
        dp[i + offset] = max(dp[i] + arr[i + offset], dp[i + offset]);
        dp[i + offset + 1] =
            max(dp[i] + arr[i + offset + 1], dp[i + offset + 1]);
        if (++cnt == offset) {
            cnt = 0;
            offset++;
        }
    }

    for (int i = n * (n + 1) / 2 - n + 1; i <= n * (n + 1) / 2; i++) {
        max_res = max(dp[i], max_res);
    }

    cout << max_res;

    return 0;
}