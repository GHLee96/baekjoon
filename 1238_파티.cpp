#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

#define INF 0x7fffffff
#define FOWARD 0
#define REVERSE 1

using namespace std;

int N, M, X;
vector<pair<int, int>> map[2][1001];
vector<int> dist;
int ans[1001] = {
    0,
};

int solution(int direction) {
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        q;
    dist.clear();
    dist.resize(N + 1, INF);

    q.push({0, X});

    dist[X] = 0;
    while (!q.empty()) {
        int t = q.top().first;
        int v = q.top().second;
        q.pop();

        if (dist[v] < t) continue;

        int size = map[direction][v].size();
        for (int i = 0; i < size; i++) {
            int next_t = map[direction][v][i].first;
            int next_v = map[direction][v][i].second;

            if (t + next_t < dist[next_v]) {
                dist[next_v] = t + next_t;
                q.push({t + next_t, next_v});
            }
        }
    }

    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> X;

    for (int i = 0; i < M; i++) {
        int s, e, t;
        cin >> s >> e >> t;
        map[FOWARD][s].push_back({t, e});
        map[REVERSE][e].push_back({t, s});
    }

    int m = 0;
    solution(FOWARD);
    for (int i = 1; i <= N; i++) {
        ans[i] += dist[i];
    }
    solution(REVERSE);
    for (int i = 1; i <= N; i++) {
        ans[i] += dist[i];
        m = max(m, ans[i]);
    }
    /*
        ****solution 2****
        for(int i = 1; i <= N; i++){
            Dijstra(i);
            // i가 X로 가는 최단거리 half
            resdist[i] = dist[X];
        }
        Dijstra(X); // 1번만 해도 x -> 각 지점의 최단거리 나온다.
        int res = 0;
        for(int i = 1; i <= N; i++){
            resdist[i] += dist[i];
            res = max(res, resdist[i]);
        }
    */
    cout << m;

    return 0;
}