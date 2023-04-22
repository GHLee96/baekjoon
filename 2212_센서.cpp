#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    int loc[N];
    vector<pair<int, int>> diff(N - 1);
    for (int i = 0; i < N; i++) {
        cin >> loc[i];
    }
    sort(loc, loc + N);

    for (int i = 0; i < N - 1; i++) {
        diff[i] = {loc[i + 1] - loc[i], i};
    }

    sort(diff.begin(), diff.end());

    if (N >= K) {
        int sum = 0;
        for (int i = N - 2; i > N - 2 - K + 1; i--) {
            sum += diff[i].first;
        }
        cout << loc[N - 1] - loc[0] - sum;
    } else {
        cout << "0";
    }

    return 0;
}