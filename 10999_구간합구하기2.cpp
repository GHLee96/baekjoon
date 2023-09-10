#include <iostream>

using namespace std;

int N, M, K;
long long arr[1000005];
long long p_sum[1 << 21];

void input() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M >> K;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
}

long long set_segment_tree(int i, int s, int e) {
    if (s == e) {
        return p_sum[i] = arr[s];
    }

    int mid = s + (e - s) / 2;
    return p_sum[i] = set_segment_tree(i * 2, s, mid) +
                      set_segment_tree(i * 2 + 1, mid + 1, e);
}

long long get_sum(int i, int s, int e, int target_s, int target_e) {

    if (e < target_s || s > target_e)
        return 0;

    if (s >= target_s && e <= target_e) {
        return p_sum[i];
    }

    int mid = s + (e - s) / 2;

    return get_sum(i * 2, s, mid, target_s, target_e) +
           get_sum(i * 2 + 1, mid + 1, e, target_s, target_e);
}

long long update(int i, int s, int e, int target_s, int target_e, int val) {

    if (e < target_s || s > target_e)
        return p_sum[i];

    if (s >= target_s && e <= target_e && s == e) {
        return p_sum[i] = p_sum[i] + val;
    }

    int mid = s + (e - s) / 2;
    return p_sum[i] = update(i * 2, s, mid, target_s, target_e, val) +
                      update(i * 2 + 1, mid + 1, e, target_s, target_e, val);
}

int main() {
    input();
    set_segment_tree(1, 1, N);

    for (int i = 0; i < M + K; i++) {
        int com;
        cin >> com;

        long long a, b, c;
        cin >> a >> b;
        if (com == 1) {
            cin >> c;

            update(1, 1, N, a, b, c);
        } else {
            cout << get_sum(1, 1, N, a, b) << '\n';
        }
    }

    return 0;
}