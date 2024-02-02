#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool is_possible(const vector<int> &arr, int n, int m, int mid) {
    int cnt = 1;
    int max_val = arr[0];
    int min_val = arr[0];

    for (int i = 1; i < n; ++i) {
        max_val = max(max_val, arr[i]);
        min_val = min(min_val, arr[i]);

        if (max_val - min_val > mid) {
            cnt++;
            max_val = arr[i];
            min_val = arr[i];
        }
    }

    return cnt <= m;
}

int sol(const vector<int> &arr, int n, int m) {
    int start = 0;
    int end = *max_element(arr.begin(), arr.end());
    int res = 0;

    while (start <= end) {
        int mid = (start + end) / 2;

        if (is_possible(arr, n, m, mid)) {
            res = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << sol(arr, n, m) << endl;

    return 0;
}
