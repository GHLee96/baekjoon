#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

struct info {
    int start, end;

    bool operator<(info b) const { return end > b.end; }
};

bool cmp(info a, info b) { return a.start < b.start; }

info arr[100005];

int main() {
    int N;
    int res = 0;

    cin >> N;

    for (int i = 0; i < N; i++) {
        int s, e;
        int dummy;
        // cin >> dummy;
        cin >> s >> e;
        arr[i] = {s, e};
    }

    sort(arr, arr + N, cmp);

    priority_queue<info> q;

    q.push(arr[0]);

    for (int i = 1; i < N; i++) {
        if (q.top().end <= arr[i].start) q.pop();

        q.push(arr[i]);
        res = max(res, (int)q.size());
    }

    cout << res;
    return 0;
}