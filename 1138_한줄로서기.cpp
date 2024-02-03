#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
pair<int, int> arr[15];

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i].second;
        arr[i].first = i;
    }

    sort(arr, arr + N, cmp);

    vector<pair<int, int>> v;
    v.push_back(arr[0]);
    for (int i = 1; i < N; i++) {
        int cnt = 0;
        for (int j = 0; j < v.size(); j++) {
            if (v[j].first > arr[i].first)
                cnt++;

            if (cnt == arr[i].second) {
                if (v.size() - 1 == j) {
                    v.insert(v.begin() + j + 1, arr[i]);
                    break;
                }
                if (v[j + 1].first > arr[i].first) {
                    v.insert(v.begin() + j + 1, arr[i]);
                    break;
                }
            }
        }
    }

    for (int i = 0; i < v.size(); i++) {
        cout << v[i].first + 1 << ' ';
    }

    return 0;
}