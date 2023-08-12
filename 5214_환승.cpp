// #include <iostream>
// #include <queue>
// #include <vector>

// using namespace std;

// struct info {
//     int num, cnt;
// };

// int N, M;
// int K;

// vector<int> visit;
// vector<vector<int>> adj;

// int bfs() {
//     queue<info> q;

//     q.push({1, 1});
//     visit[1] = 1;

//     if (N == 1) return 1;

//     while (!q.empty()) {
//         int now = q.front().num;
//         int cnt = q.front().cnt;
//         q.pop();
//         for (auto next : adj[now]) {
//             if (visit[next]) continue;
//             visit[next] = 1;

//             if (next == N) return cnt + 1;

//             if (next > N)
//                 q.push({next, cnt});
//             else {
//                 q.push({next, cnt + 1});
//             }
//         }
//     }

//     return 0;
// }

// void input() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     cin >> N >> K >> M;

//     visit.resize(N + 1 + M);
//     adj.resize(N + 1 + M);
//     for (int i = 0; i < M; i++) {
//         for (int j = 0; j < K; j++) {
//             int n;
//             cin >> n;

//             adj[i + N + 1].push_back(n);
//             adj[n].push_back(i + N + 1);
//         }
//     }
// }

// int main() {
//     input();

//     int res = bfs();

//     if (res)
//         cout << res;
//     else
//         cout << -1;

//     return 0;
// }

// 오후 11:24

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int cnt = 0;
int min_path = 2100000000;
vector<int> v;
int now, school;
int dir[2] = {-1, 1};
int visited[100001];

void bfs(int cur) {
    queue<int> q;
    q.push(cur);
    visited[cur] = 1;

    while (!q.empty()) {
        int now = q.front();
        q.pop();
        if (now == school) {
            if (min_path > visited[now]) min_path = visited[now];
        }

        int next;
        for (int i = 0; i < 2; i++) {
            next = now + dir[i];

            if (next < 0 || next > 100000) continue;

            if (visited[next] > 0) continue;
            q.push(next);
            visited[next] = visited[now] + 1;
        }
        // 양쪽을 다 가본 후에!
        next = now * 2;
        if (next > 100000) continue;
        if (visited[next] > 0)
            continue;  // 이미 방문한 노드면 더 진행 안 하고
                       // 큐에서 하나 더 꺼내기.

        q.push(next);
        visited[next] = visited[now] + 1;
    }
}

int main(void) {
    cin >> now >> school;

    bfs(now);

    cout << min_path - 1;
}