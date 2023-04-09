#include <iostream>
#include <queue>
#include <vector>

#define INF 0x7fffffff

using namespace std;

vector<pair<int, int>> map[1001];
priority_queue<int> q_city[1001];
int dist[1001];

int solution(int s, int k) {
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        q;

    q.push(make_pair(0, s));
    q_city[1].push(0);

    while (!q.empty()) {
        int cost = q.top().first;
        int v = q.top().second;
        q.pop();

        for (int i = 0; i < map[v].size(); i++) {
            int next_v = map[v][i].first;
            int next_cost = map[v][i].second;

            if (q_city[next_v].size() < k) {
                q_city[next_v].push(cost + next_cost);
                q.push(make_pair(cost + next_cost, next_v));
            } else if (q_city[next_v].top() > cost + next_cost) {
                q_city[next_v].pop();
                q_city[next_v].push(cost + next_cost);
                q.push(make_pair(cost + next_cost, next_v));
            }
        }
    }

    return 0;
}

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, k;
    int a, b, c;
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
    }

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        map[a].push_back(make_pair(b, c));
    }

    solution(1, k);

    for (int i = 1; i <= n; i++) {
        if (q_city[i].size() < k) {
            cout << "-1\n";
        } else {
            cout << q_city[i].top() << "\n";
        }
    }
    return 0;
}