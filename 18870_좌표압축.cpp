#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;

    cin >> N;
    vector<int> arr(N);
    map<int, int> m;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        m[arr[i]] = 1;
    }
    // vector<int> sorted_arr = arr;
    // sort(sorted_arr.begin(), sorted_arr.end());
    // sorted_arr.erase(unique(sorted_arr.begin(), sorted_arr.end()),
    //                  sorted_arr.end());

    // for (int i = 0; i < N; i++) {
    //     int idx = lower_bound(sorted_arr.begin(), sorted_arr.end(), arr[i]) -
    //               sorted_arr.begin();
    //     cout << idx << ' ';
    // }

    // map으로도 가능
    int idx = 0;
    for (auto x : m) {
        m[x.first] = idx++;
    }

    for (int i = 0; i < N; i++) {
        cout << m[arr[i]] << ' ';
    }

    return 0;
}