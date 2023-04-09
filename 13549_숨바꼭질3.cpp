/*

    우선순위큐, deque로도 풀이 가능...

*/

#include <cstring>
#include <iostream>
#include <queue>

#define check(k) (((k) >= 0 && (k) <= 100000) ? 1 : 0)
#define INF 0x7fffffff

using namespace std;

int dp[100001];

int solution(int N, int K) {
    queue<int> q;
    q.push(N);

    dp[N] = 0;
    while (!q.empty()) {
        int idx = q.front();
        q.pop();

        if (idx == K) {
            return dp[K];
        }

        if (check(idx * 2) && dp[idx * 2] > dp[idx]) {
            dp[idx * 2] = dp[idx];
            q.push(idx * 2);
        }

        if (check(idx + 1) && dp[idx + 1] > dp[idx] + 1) {
            dp[idx + 1] = dp[idx] + 1;
            q.push(idx + 1);
        }

        if (check(idx - 1) && dp[idx - 1] > dp[idx] + 1) {
            dp[idx - 1] = dp[idx] + 1;
            q.push(idx - 1);
        }
    }

    return dp[K];
}

int main() {
    int N, K;
    cin >> N >> K;

    for (int i = 0; i < 100001; i++) {
        dp[i] = INF;
    }

    cout << solution(N, K);
    return 0;
}