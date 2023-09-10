#include <iostream>

using namespace std;

int N, M;
int arr[100005];
int p_min[1 << 18];
int p_min_i[1 << 18];

void input() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
}

void set_min_segment_tree(int i, int s, int e) {
    if (s == e) {
        p_min[i] = arr[s];
        p_min_i[i] = s;
        return;
    }

    int l = i * 2;
    int r = i * 2 + 1;
    set_min_segment_tree(l, s, (s + e) / 2);
    set_min_segment_tree(r, (s + e) / 2 + 1, e);

    if (p_min[l] < p_min[r]) {
        p_min[i] = p_min[l];
        p_min_i[i] = p_min_i[l];
    } else if (p_min[l] == p_min[r]) {
        p_min[i] = p_min[l];
        p_min_i[i] = min(p_min_i[l], p_min_i[r]);
    } else {
        p_min[i] = p_min[r];
        p_min_i[i] = p_min_i[r];
    }
}

void update(int i, int s, int e, int target_s, int target_e, int val) {
    if (target_s > e || target_e < s) {
        return;
    }

    if (s == e && target_s == s) {
        p_min[i] = val;
        return;
    }

    int l = i * 2;
    int r = i * 2 + 1;
    update(l, s, (s + e) / 2, target_s, target_e, val);
    update(r, (s + e) / 2 + 1, e, target_s, target_e, val);

    if (p_min[l] < p_min[r]) {
        p_min[i] = p_min[l];
        p_min_i[i] = p_min_i[l];
    } else if (p_min[l] == p_min[r]) {
        p_min[i] = p_min[l];
        p_min_i[i] = min(p_min_i[l], p_min_i[r]);
    } else {
        p_min[i] = p_min[r];
        p_min_i[i] = p_min_i[r];
    }
}

int main() {
    input();
    set_min_segment_tree(1, 1, N);

    cin >> M;
    for (int i = 0; i < M; i++) {
        int com, a, b;
        cin >> com;

        if (com == 1) {
            cin >> a >> b;
            update(1, 1, N, a, a, b);
        } else {
            cout << p_min_i[1] << '\n';
        }
    }

    return 0;
}