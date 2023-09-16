#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int L, K, C;
vector<int> arr;
int ans_first_cut;
int first_cut;

bool is_possible(int target) {

    int cnt = 0;
    int last_cut = L;

    if (last_cut - arr[arr.size() - 1] > target)
        return false;
    for (int i = arr.size() - 1; i > 0; i--) {
        if (arr[i] - arr[i - 1] > target)
            return false;

        if (last_cut - arr[i - 1] <= target)
            continue;

        cnt++;
        last_cut = arr[i];
    }

    if (cnt < C) {
        first_cut = arr[1];
    } else {
        first_cut = last_cut;
    }

    return cnt <= C;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> L >> K >> C;
    arr.resize(K + 1);
    for (int i = 1; i <= K; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());

    int l = 1;
    int r = L;

    while (l != r) {
        int mid = (l + r) / 2;

        if (!is_possible(mid)) {
            l = mid + 1;
        } else {
            r = mid;
            ans_first_cut = first_cut;
        }
    }

    cout << r << ' ' << ans_first_cut;

    return 0;
}
