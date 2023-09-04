#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

struct info {
    int start, end, i;

    bool operator<(info b) const { return end > b.end; }
};

bool cmp(info a, info b) { return a.start < b.start; }

info arr[100005];
int num[100005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    int res = 0;

    cin >> N;

    for (int i = 0; i < N; i++) {
        int n, s, e;
        cin >> n >> s >> e;
        arr[i] = {s, e, --n};
    }

    sort(arr, arr + N, cmp);

    priority_queue<info> q;

    q.push(arr[0]);
    int cnt = 1;
    num[arr[0].i] = cnt;

    for (int i = 1; i < N; i++) {
        int next;
        if (q.top().end <= arr[i].start) {
            next = num[q.top().i];
            q.pop();
        } else {
            cnt++;
            next = cnt;
        }

        num[arr[i].i] = next;
        q.push(arr[i]);
    }

    cout << cnt << '\n';
    for (int i = 0; i < N; i++) {
        cout << num[i] << '\n';
    }
    return 0;
}