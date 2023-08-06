#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    vector<pair<int, int>> arr;
    cin >> n;

    arr.resize(n);
    for (int i = 0; i < n; i++) cin >> arr[i].first >> arr[i].second;

    sort(arr.begin(), arr.end(), cmp);

    for (auto x : arr) {
        cout << x.first << " " << x.second << "\n";
    }

    return 0;
}