#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

#define INF 0x7fffffff
using namespace std;

vector<pair<int, int>> map[501];
int road[501][501] = {
    0,
};
int dist[501];
vector<int> pre[501];

int solution(int s, int d) {
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        q;

    q.push(make_pair(0, s));
    dist[s] = 0;

    while (!q.empty()) {
        int cost = q.top().first;
        int v = q.top().second;
        q.pop();

        if (dist[v] < cost) continue;

        for (int i = 0; i < (int)map[v].size(); i++) {
            int next_cost = map[v][i].second;
            int next_v = map[v][i].first;
            if (road[v][next_v] != 0) {
                if (dist[next_v] > cost + next_cost) {
                    dist[next_v] = cost + next_cost;
                    q.push(make_pair(dist[next_v], next_v));
                    pre[next_v].clear();
                    pre[next_v].push_back(v);
                } else if (dist[next_v] == cost + next_cost) {
                    pre[next_v].push_back(v);
                }
            }
        }
    }
    return 0;
}

// void erase(int s, int d) {
//     road[s][pre[d][0]] = 0;
//     int j;
//     for (j = 1; j < (int)pre[d].size(); j++) {
//         road[pre[d][j - 1]][pre[d][j]] = 0;
//     }
//     road[pre[d][j]][d] = 0;
// }

void erase(int cur) {
    for (auto x : pre[cur]) {
        for (int i = 0; i < map[x].size(); i++) {
            if (map[x][i].first == cur && road[x][cur]) {
                road[x][cur] = 0;
                erase(x);
                break;
            }
        }
    }
}

int main() {
    int N, M;
    int S, D;
    int U, V, P;

    while (1) {
        cin >> N >> M;
        if (N == 0 && M == 0) break;

        cin >> S >> D;

        for (int i = 0; i < N; i++) {
            dist[i] = INF;
        }
        memset(road, 0, sizeof(road));

        for (int i = 0; i < M; i++) {
            cin >> U >> V >> P;
            map[U].push_back(make_pair(V, P));
            road[U][V] = 1;
        }
        solution(S, D);
        if (dist[D] == INF) {
            cout << "-1\n";
            continue;
        }
        erase(D);

        for (int i = 0; i < N; i++) {
            dist[i] = INF;
        }
        solution(S, D);

        if (dist[D] == INF) {
            cout << "-1\n";
        } else {
            cout << dist[D] << "\n";
        }

        for (int i = 0; i < N; i++) {
            map[i].clear();
            pre[i].clear();
        }
    }

    return 0;
}