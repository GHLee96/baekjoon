#include <iostream>
#include <queue>
#define INF 0x7fffffff
#define check(k) (((k) >= 0 && (k) <= 100000) ? 1 : 0)

using namespace std;

int dp[100001];
int pre[100001];

int N, K;

typedef struct info {
    int current, prev;
} Info;

Info soltuion() {
    for (int i = 0; i < 100001; i++) {
        dp[i] = INF;
        pre[i] = INF;
    }

    Info info;
    info.current = N;
    dp[N] = 0;
    queue<Info> q;

    q.push(info);
    while (!q.empty()) {
        info = q.front();
        if (info.current == K) return info;

        q.pop();

        int arr[3] = {info.current + 1, info.current - 1, info.current * 2};
        for (auto next : arr) {
            if (K < info.current && (next == arr[0] || next == arr[2]))
                continue;

            if (!check(next)) continue;

            if (dp[next] > dp[info.current] + 1) {
                dp[next] = dp[info.current] + 1;
                q.push({next, info.current});
                pre[next] = info.current;
            }
        }
    }

    return info;
}

void find_route() {
    vector<int> ans;
    int a = pre[K];
    if (a == INF) {
        cout << N;
        return;
    }
    while (a != N) {
        ans.push_back(a);
        a = pre[a];
    }
    cout << N << " ";
    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i] << " ";
    }
    cout << K;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    soltuion();
    cout << dp[K] << endl;
    find_route();

    return 0;
}