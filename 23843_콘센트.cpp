#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;
priority_queue<int, vector<int>, greater<int>> q;
int times[10005];

bool cmp(int a, int b) { return a > b; }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> times[i];
    }

    sort(times, times + N, cmp);

    for (int i = 0; i < M; i++) {
        q.push(0);
    }

    int res = 0;
    for (int i = 0; i < N; i++) {
        int tmp = q.top() + times[i];
        q.pop();
        q.push(tmp);

        res = max(res, tmp);
    }

    cout << res << endl;

    return 0;
}