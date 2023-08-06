#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    int arr[N];
    for (int i = 0; i < N; i++) cin >> arr[i];

    int diff[N - 1];

    for (int i = 0; i < N - 1; i++) {
        diff[i] = arr[i + 1] - arr[i];
    }

    sort(diff, diff + N - 1);

    int res = 0;
    for (int i = 0; i < N - K; i++) {
        res += diff[i];
    }
    cout << res;
    return 0;
}