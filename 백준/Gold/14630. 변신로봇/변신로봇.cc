#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct info {
    int cost, num;

    bool operator<(info b) const { return cost > b.cost; }
};

string arr[1005];
int N;

int s, e;
vector<int> dist;

void sol() {
    dist.resize(N + 5, 0x7fffffff);
    priority_queue<info> q;
    q.push({ 0, s });
    dist[s] = 0;

    while (!q.empty()) {
        info now = q.top();
        q.pop();

        if (dist[now.num] < now.cost)
            continue;

        for (int i = 1; i <= N; i++) {
            int cost = 0;

            for (int j = 0; j < arr[i].size(); j++) {
                int a = arr[i][j] - '0';
                int b = arr[now.num][j] - '0';

                cost += (a - b) * (a - b);
            }

            if (dist[i] <= dist[now.num] + cost)
                continue;

            dist[i] = dist[now.num] + cost;
            q.push({ dist[i], i });
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    cin >> s >> e;

    sol();

    cout << dist[e] << endl;

    return 0;
}