#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

pair<int, int> info[300001];
int bag[300001];

int N, K;

long long solution() {
    long long ret = 0;
    priority_queue<int> q;
    int bag_i = 0;

    int size = N;
    int idx = 0;
    for (int i = 0; i < K; i++) {
        while (bag[i] >= info[idx].first) {
            q.push(info[idx++].second);
        }

        if (!q.empty()) {
            ret += (long long)q.top();
            q.pop();
        }
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> info[i].first >> info[i].second;
        // int m, v;
        // cin >> m >> v;
        // info.push_back({m, v});
    }
    for (int i = 0; i < K; i++) {
        cin >> bag[i];
        // int c;
        // cin >> c;
        // bag.push_back(c);
    }

    sort(info, info + N);
    sort(bag, bag + K);

    cout << solution();

    return 0;
}