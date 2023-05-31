#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct info {
    int s, e, w;
};
struct compare {
    bool operator()(info &a, info &b) { return a.w > b.w; }
};

priority_queue<info, vector<info>, compare> graph;
// vector<info> graph;
vector<int> parent;

int N, M;

// bool cmp(info a, info b) { return a.w < b.w; };

void input() {
    cin >> N >> M;

    // graph.resize(M);
    parent.resize(N + 1);

    for (int i = 1; i <= N; i++) parent[i] = i;

    for (int i = 0; i < M; i++) {
        int s, e, w;
        cin >> s >> e >> w;
        graph.push({s, e, w});
    }
}

int get_parent(int i) {
    if (parent[i] == i) return i;
    return get_parent(parent[i]);
}

int solution() {
    int ret = 0;

    while (!graph.empty()) {
        info t = graph.top();
        graph.pop();
        int parent_s = get_parent(t.s);
        int parent_e = get_parent(t.e);
        if (parent_s == parent_e) continue;

        ret += t.w;
        if (parent_s < parent_e)
            parent[parent_s] = parent_e;  // parent의 parent를 바꿔야한다.
        else
            parent[parent_e] = parent_s;
    }

    return ret;
}

int main() {
    input();
    // sort(graph.begin(), graph.end(), cmp);
    cout << solution();

    return 0;
}