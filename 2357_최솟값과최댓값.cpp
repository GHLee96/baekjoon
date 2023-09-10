#include <iostream>

using namespace std;

int N, M;
int arr[100005];
int p_max[1 << 18];
int p_min[1 << 18];

void input() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
}

int set_max_segment_tree(int i, int s, int e) {
    if (s == e) {
        return p_max[i] = arr[s];
    }

    return p_max[i] = max(set_max_segment_tree(i * 2, s, (s + e) / 2),
                          set_max_segment_tree(i * 2 + 1, (s + e) / 2 + 1, e));
}

int get_max(int i, int s, int e, int target_s, int target_e) {

    if (e < target_s || s > target_e)
        return 0;

    if (s >= target_s && e <= target_e) {
        return p_max[i];
    }

    return max(get_max(i * 2, s, (s + e) / 2, target_s, target_e),
               get_max(i * 2 + 1, (s + e) / 2 + 1, e, target_s, target_e));
}

int set_min_segment_tree(int i, int s, int e) {
    if (s == e) {
        return p_min[i] = arr[s];
    }

    return p_min[i] = min(set_min_segment_tree(i * 2, s, (s + e) / 2),
                          set_min_segment_tree(i * 2 + 1, (s + e) / 2 + 1, e));
}

int get_min(int i, int s, int e, int target_s, int target_e) {

    if (e < target_s || s > target_e)
        return 0x7fffffff;

    if (s >= target_s && e <= target_e) {
        return p_min[i];
    }

    return min(get_min(i * 2, s, (s + e) / 2, target_s, target_e),
               get_min(i * 2 + 1, (s + e) / 2 + 1, e, target_s, target_e));
}

int main() {
    input();
    set_max_segment_tree(1, 1, N);
    set_min_segment_tree(1, 1, N);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        cout << get_min(1, 1, N, a, b) << ' ' << get_max(1, 1, N, a, b) << '\n';
    }

    return 0;
}