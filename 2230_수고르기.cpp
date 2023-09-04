#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, M;

vector<int> arr;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;

    arr.resize(N);
    for (int i = 0; i < N; i++) cin >> arr[i];

    sort(arr.begin(), arr.end());

    int min_diff = 0x7fffffff;

    int l = 0;
    int r = 0;

    while (l < N && r < N) {
        if (arr[r] - arr[l] >= M) {
            min_diff = min(min_diff, arr[r] - arr[l]);
            l++;
        } else {
            r++;
        }
    }

    cout << min_diff;

    return 0;
}