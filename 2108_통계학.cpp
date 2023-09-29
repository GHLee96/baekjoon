#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

int N;
int arr[500005];
int cnt[10000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    int sum = 0;
    int avg;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        sum += arr[i];

        cnt[arr[i] + 4000]++;
    }

    avg = round((double)sum / N);

    sort(arr, arr + N);

    int max_cnt = 0;
    int max_val = 0;
    int same_cnt = 0;
    for (int i = 0; i <= 8001; i++) {
        if (max_cnt < cnt[i]) {
            max_cnt = cnt[i];
            max_val = i - 4000;
            same_cnt = 0;
        } else if (cnt[i] != 0 && max_cnt == cnt[i]) {
            same_cnt++;

            if (same_cnt == 1) {
                max_val = i - 4000;
            }
        }
    }

    cout << avg << '\n';
    cout << arr[N / 2] << '\n';
    cout << max_val << '\n';
    cout << arr[N - 1] - arr[0];

    return 0;
}