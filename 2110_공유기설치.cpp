#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, C;
vector<int> arr;
int main() {
    cin >> N >> C;

    arr.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int l = 1;
    int r = arr[N - 1];
    int res = l;

    // 1 2 4 8 9
    while (l <= r) {
        int mid = (l + r) / 2;

        int i = 0;
        int cnt = 0;
        while (1) {
            auto it = lower_bound(arr.begin() + i, arr.end(), arr[i] + mid);
            if (it == arr.end())
                break;
            i = it - arr.begin();
            cnt++;
        }

        if (cnt < C - 1) {
            r = mid - 1;
        } else {
            res = max(res, mid);
            l = mid + 1;
        }
    }

    cout << res;

    return 0;
}