#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct info {
    int start, end, idx;

    bool operator<(info b) const { return start < b.start; }
};

int N, Q;

vector<int> parent;

int get_parent(int a) {
    if (a == parent[a]) return a;
    return parent[a] = get_parent(parent[a]);
}

void set_union(int a, int b) {
    a = get_parent(a);
    b = get_parent(b);

    parent[a] = parent[b];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> Q;

    parent.resize(N + 1);
    for (int i = 0; i <= N; i++) {
        parent[i] = i;
    }

    vector<info> arr(N + 1);
    for (int i = 1; i <= N; i++) {
        int y;
        cin >> arr[i].start >> arr[i].end;
        cin >> y;
        arr[i].idx = i;
    }

    sort(arr.begin(), arr.end());

    int idx = arr[1].idx;
    int end = arr[1].end;
    for (int i = 2; i <= N; i++) {
        if (arr[i].start <= end) {
            set_union(idx, arr[i].idx);
            if (arr[i].end > end) {
                idx = arr[i].idx;
                end = arr[i].end;
            }
        } else {
            idx = arr[i].idx;
            end = arr[i].end;
        }
    }

    for (int i = 0; i < Q; i++) {
        int a, b;
        cin >> a >> b;
        if (get_parent(a) == get_parent(b))
            cout << 1;
        else
            cout << 0;
        cout << '\n';
    }

    return 0;
}