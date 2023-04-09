#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define INF 0x7FFFFFFF

vector<pair<int, int>> map[20001];

int dist[20001];
int V, E;
int S;

int count1 = 0;

int find_shortest_path(int s) {
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        q;

    dist[s] = 0;
    q.push(make_pair(0, s));

    while (!q.empty()) {
        int cost = q.top().first;
        int v = q.top().second;
        q.pop();

        if (cost > dist[v]) {
            cout << ++count1 << "saifjoaisjdfiasjofiajsdf \n";
            continue;
        }
        for (int j = 0; j < map[v].size(); j++) {
            int next_v = map[v][j].first;
            int weight = map[v][j].second;

            if (dist[next_v] > cost + weight) {
                dist[next_v] = cost + weight;
                q.push(make_pair(dist[next_v], next_v));
            }
        }
    }

    return 0;
}

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> V >> E;
    cin >> S;

    for (int i = 1; i <= V; i++) {
        dist[i] = INF;
    }

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        map[u].push_back(make_pair(v, w));
    }

    find_shortest_path(S);

    for (int i = 1; i <= V; i++) {
        if (dist[i] != INF)
            cout << dist[i] << "\n";
        else
            cout << "INF"
                 << "\n";
    }

    return 0;
}