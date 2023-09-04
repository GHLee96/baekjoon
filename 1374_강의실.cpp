#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct info {
    int s, e;
};

struct cmp2 {
    bool operator()(info a, info b) const { return a.e > b.e; }
};

bool cmp1(info a, info b) { return a.s < b.s; }

int N;
priority_queue<info, vector<info>, cmp2> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    vector<info> arr(N);
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        cin >> arr[i].s >> arr[i].e;
    }

    sort(arr.begin(), arr.end(), cmp1);
    q.push(arr[0]);
    int max_len = 1;
    for (int i = 1; i < N; i++) {
        if (q.top().e <= arr[i].s) q.pop();

        q.push(arr[i]);

        max_len = max(max_len, (int)q.size());
    }
    cout << max_len;
    return 0;
}