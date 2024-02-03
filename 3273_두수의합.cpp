#include <algorithm>
#include <iostream>

using namespace std;

int N;
int arr[100005];
int target;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    cin >> target;

    sort(arr, arr + N);

    int l = 0;
    int r = N - 1;
    int cnt = 0;
    while (l < r) {
        if (arr[l] + arr[r] == target) {
            cnt++;
            l++;
            r--;
        } else if (arr[l] + arr[r] > target) {
            r--;
        } else {
            l++;
        }
    }
    cout << cnt << endl;
    return 0;
}