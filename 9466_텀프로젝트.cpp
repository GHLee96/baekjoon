#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> v;
vector<bool> visit;
vector<int> list;
vector<int> parent;
int cnt;

int get_parent(int i) {
    if (parent[i] == i) return i;
    return parent[i] = get_parent(parent[i]);
}

void sol(int i) {
    if (visit[i] == 1) return;
    visit[i] = 1;

    if (v[i] == i) {
        visit[i] = 1;
        cnt--;
        return;
    }

    if (get_parent(v[i]) == get_parent(i)) {
        int idx = v[i];
        while (idx != i) {
            cnt--;
            idx = v[idx];
        }
        cnt--;
        return;
    }

    // list.push_back(i);
    // auto it = find(list.begin(), list.end(), v[i]);
    // if (it != list.end()) {
    //     while (it != list.end()) {
    //         int idx = it - list.begin();
    //         visit[list[idx]] = 1;
    //         cnt--;
    //         it++;
    //     }
    //     return;
    // }

    parent[v[i]] = get_parent(i);
    sol(v[i]);
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for (int i = 1; i <= T; i++) {
        cin >> N;

        v.clear();
        v.resize(N + 1);
        visit.clear();
        visit.resize(N + 1, false);
        parent.clear();
        parent.resize(N + 1);
        cnt = N;
        for (int j = 1; j <= N; j++) {
            cin >> v[j];
            parent[j] = j;
        }

        for (int j = 1; j <= N; j++) {
            list.clear();
            sol(j);
        }
        cout << cnt << "\n";
    }

    return 0;
}