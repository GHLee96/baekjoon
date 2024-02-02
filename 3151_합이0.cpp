#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

vector<long long> arr;
map<long long, long long> cnt;
long long N;

void input() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("test.txt", "r", stdin);

    cin >> N;

    arr.resize(N);
    for (long long i = 0; i < N; i++) {
        cin >> arr[i];
        cnt[arr[i]]++;
    }
}

void solution() {

    long long res = 0;

    sort(arr.begin(), arr.end());

    arr.erase(unique(arr.begin(), arr.end()), arr.end());

    for (long long i = 0; i < (int)arr.size() - 2; i++) {
        long long l = i + 1;
        long long r = arr.size() - 1;

        while (l < r) {
            long long sum = arr[i] + arr[l] + arr[r];

            if (sum == 0) {
                res += cnt[arr[i]] * cnt[arr[l]] * cnt[arr[r]];
                l++;
                r--;
            } else if (sum < 0) {
                l++;
            } else {
                r--;
            }
        }
    }

    for (long long i = 0; i < (int)arr.size(); i++) {
        if (arr[i] == 0)
            continue;
        res += cnt[-arr[i] * 2] * cnt[arr[i]] * (cnt[arr[i]] - 1) / 2;
    }

    if (cnt[0] >= 3) {
        res += cnt[0] * (cnt[0] - 1) * (cnt[0] - 2) / 3 / 2;
    }

    cout << res << endl;
}

int main() {
    input();
    solution();

    return 0;
}