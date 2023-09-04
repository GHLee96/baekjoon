#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N, T;
int parent[100001];
int cnt[100001];
vector<int> population;

int Find(int now) {
    if (parent[now] == now) return now;
    return parent[now] = Find(parent[now]);
}

void Union(int a, int b) {
    int root_a = Find(a);
    int root_b = Find(b);

    if (root_a == root_b) return;
    parent[root_a] = root_b;
    population[root_b] += population[root_a];
    population[root_a] = 0;

    cnt[root_b] += cnt[root_a];
    cnt[root_a] = 0;
}

void sol(int cmd, int a, int b) {
    if (cmd == 1) {
        Union(a, b);
    } else {
        int root_a = Find(a);
        int root_b = Find(b);

        if (population[root_a] == population[root_b]) {
            population[root_a] = population[root_b] = 0;
            cnt[root_a] = cnt[root_b] = 0;
        } else if (population[root_a] > population[root_b]) {
            parent[root_b] = root_a;
            population[root_a] -= population[root_b];

            population[root_b] = 0;
            cnt[root_b] = 0;

        } else {
            parent[root_a] = root_b;
            population[root_b] -= population[root_a];

            population[root_a] = 0;
            cnt[root_a] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> T;

    population.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> population[i];
        parent[i] = i;
        cnt[i] = 1;
    }

    for (int i = 0; i < T; i++) {
        int cmd;
        int a, b;
        cin >> cmd >> a >> b;

        sol(cmd, a, b);
    }

    sort(population.begin(), population.end());
    auto it = upper_bound(population.begin(), population.end(), 0);
    int idx = it - population.begin();
    cout << N - idx + 1 << '\n';
    for (int i = idx; i <= N; i++) {
        if (!population[i]) continue;
        cout << population[i] << ' ';
    }

    return 0;
}