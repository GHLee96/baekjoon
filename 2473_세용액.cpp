#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int N;
long long sum;
long long min_ans = 0x7ffffffffffffff;
vector<long long> arr;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    arr.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    sort(arr.begin(), arr.end());

    int l = 0;
    int r = N - 1;

    vector<long long> ans(3);

    for (int i = 0; i < N - 2; i++) {
        l = i + 1;
        r = N - 1;

        while (l < r) {
            sum = arr[r] + arr[l] + arr[i];
            if (min_ans > abs(sum)) {
                min_ans = abs(sum);
                ans = {arr[i], arr[l], arr[r]};
            }

            if (sum > 0)
                r--;
            else if (sum < 0)
                l++;
            else
                break;
        }
    }

    for (auto x : ans) {
        cout << x << " ";
    }

    return 0;
}
