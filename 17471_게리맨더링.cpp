#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N;
vector<int> area;
int visit;
vector<vector<int>> map;
vector<int> population;
int total_pop;
int res = 0x7fffffff;

void bfs(int idx) {
    queue<int> q;
    q.push(idx);

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        visit |= 1 << v;

        for (int i = 0; i < map[v].size(); i++) {
            int next_v = map[v][i];
            if ((visit >> next_v) & 1) continue;
            bfs(next_v);
        }
    }
}

void combi(int d, int idx) {
    if (d == 0) {
        int last_i;
        int sum = 0;

        visit = 0;
        int visit1 = 0;
        // 체크
        for (auto x : area) {
            visit1 |= (1 << x);
            last_i = x;
            sum += population[x];
        }

        visit = visit1 ^ ((1 << (N + 1)) - 2);
        bfs(last_i);

        if ((visit & visit1) != visit1) return;

        visit = visit1;

        for (int i = 1; i <= N; i++) {
            if (((visit >> i) & 1) == 0) {
                bfs(i);
                break;
            }
        }
        if (visit == (1 << (N + 1)) - 2) {
            res = min(res, abs(total_pop - sum - sum));
        }
    }

    for (int i = idx; i < N; i++) {
        area.push_back(i);
        combi(d - 1, i + 1);
        area.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    map.resize(N + 1);
    population.resize(N + 1);

    for (int i = 1; i <= N; i++) {
        cin >> population[i];
        total_pop += population[i];
    }

    for (int i = 1; i <= N; i++) {
        int n;
        cin >> n;
        map[i].resize(n);
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    for (int i = 1; i < N; i++) {
        combi(i, 1);
    }

    if (res == 0x7fffffff)
        cout << "-1";
    else
        cout << res;

    return 0;
}