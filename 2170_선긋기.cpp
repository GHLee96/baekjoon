#include <algorithm>
#include <iostream>

using namespace std;

int N;
pair<int, int> arr[1000005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {

        cin >> arr[i].first >> arr[i].second;
    }

    sort(arr, arr + N);

    int s = arr[0].first;
    int e = arr[0].second;
    int res = 0;

    for (int i = 1; i < N; i++) {

        if (e >= arr[i].first) {
            e = max(e, arr[i].second);
        } else {
            res += e - s;
            s = arr[i].first;
            e = arr[i].second;
        }
    }
    res += e - s;

    cout << res;

    return 0;
}