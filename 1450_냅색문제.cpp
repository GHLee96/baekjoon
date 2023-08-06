#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, C;
vector<int> arr;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> C;
    arr.resize(N);
    for (int i = 0; i < N; i++) cin >> arr[i];

    vector<int> set1, set2;
    int n1 = N / 2;
    int n2 = N - n1;

    for (int i = 0; i < (1 << n1); i++) {
        long long sum = 0;
        for (int j = 0; j < n1; j++) {
            if (i & (1 << j)) {
                sum += arr[j];
            }
        }
        if (sum <= 1000000000) set1.push_back(sum);
    }

    for (int i = 0; i < (1 << n2); i++) {
        long long sum = 0;
        for (int j = 0; j < n2; j++) {
            if (i & (1 << j)) {
                sum += arr[n1 + j];
            }
        }
        if (sum <= 1000000000) set2.push_back(sum);
    }

    sort(set1.begin(), set1.end());
    sort(set2.begin(), set2.end());

    int count = 0;
    for (auto x : set1) {
        int size = upper_bound(set2.begin(), set2.end(), C - x) - set2.begin();
        count += size;
    }

    cout << count;
    return 0;
}