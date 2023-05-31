#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int N;
pair<int, int> x[100001];  // {value, index}
pair<int, int> y[100001];
pair<int, int> z[100001];
int check[100001];

struct info {
    int s, e, w;
};

struct Compare {
    bool operator()(const info& a, const info& b) { return a.w > b.w; }
};

priority_queue<info, vector<info>, Compare> q;

bool cmp(pair<int, int>& a, pair<int, int>& b) { return a.first < b.first; }

void find_map(pair<int, int> arr[]) {
    for (int i = 0; i < N - 1; i++) {
        q.push({arr[i].second, arr[i + 1].second,
                arr[i + 1].first - arr[i].first});
    }
}

// find
int get_parent(int node) {
    if (check[node] == node) return node;
    return get_parent(check[node]);
}

// union
void union_parent(int node_a, int node_b) {
    int parent_a = get_parent(node_a);
    int parent_b = get_parent(node_b);
    if (parent_a < parent_b)
        check[parent_b] = parent_a;
    else
        check[parent_a] = parent_b;
}

bool is_cycle(int node_a, int node_b) {
    if (get_parent(node_a) == get_parent(node_b)) return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x[i].first >> y[i].first >> z[i].first;
        x[i].second = i;
        y[i].second = i;
        z[i].second = i;

        check[i] = i;
    }

    sort(x, x + N, cmp);
    sort(y, y + N, cmp);
    sort(z, z + N, cmp);

    find_map(x);
    find_map(y);
    find_map(z);

    int sum = 0;
    int cnt = 0;

    while (!q.empty()) {
        info c = q.top();
        q.pop();
        if (!is_cycle(c.s, c.e)) {
            sum += c.w;
            union_parent(c.s, c.e);
            if (++cnt == N - 1) break;
        }
    }

    cout << sum;
    return 0;
}