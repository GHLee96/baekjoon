#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, S;
    cin >> N >> S;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    long long count = 0;
    int n1 = N / 2;
    int n2 = N - n1;

    vector<int> set1, set2;  // N <= 40이므로 나눠서 계산

    for (int i = 0; i < (1 << n1); i++) {
        int sum = 0;
        for (int j = 0; j < n1; j++) {
            if (i & (1 << j)) {
                sum += arr[j];
            }
        }
        set1.push_back(sum);
    }

    for (int i = 0; i < (1 << n2); i++) {
        int sum = 0;
        for (int j = 0; j < n2; j++) {
            if (i & (1 << j)) {
                sum += arr[n1 + j];
            }
        }
        set2.push_back(sum);
    }

    sort(set2.begin(), set2.end());
    for (auto x : set1) {
        auto range = equal_range(set2.begin(), set2.end(), S - x);
        int len = range.second - range.first;
        // int len = upper_bound(set2.begin(), set2.end(), S - x) -
        //           lower_bound(set2.begin(), set2.end(), S - x);
        count += len;
    }

    if (S == 0) count--;
    cout << count;

    return 0;
}

/* 
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int N, S;
int mid;
vector<int> v;
long long cnt;

map<int, int> sum_map;

void sol1(int idx, int sum) {
    if (idx >= mid) {
        sum_map[sum]++;
        return;
    }

    sol1(idx + 1, sum);
    sol1(idx + 1, sum + v[idx]);

    return;
}

void sol2(int idx, int sum) {
    if (idx >= N) {
        cnt += sum_map[S - sum];
        return;
    }

    sol2(idx + 1, sum);
    sol2(idx + 1, sum + v[idx]);

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> S;
    v.resize(N);
    for (int i = 0; i < N; i++) cin >> v[i];

    mid = N / 2;

    sol1(0, 0);
    sol2(mid, 0);

    if (S == 0) cnt--;
    cout << cnt;
    return 0;
} */