#include <iostream>

using namespace std;

int N, M;
long long arr[1000005];
long long p_sum[1 << 21];

void input() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
}

long long set_tree(int i, int s, int e) {

    if (s == e) {
        return p_sum[i] = arr[s] % 2 ? 1 : 0; // 홀수 이면 1
    }

    int mid = s + (e - s) / 2;

    return p_sum[i] = set_tree(i * 2, s, mid) + set_tree(i * 2 + 1, mid + 1, e);
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

long long update(int i, int s, int e, int target_s, int val) {

    if (s > target_s || e < target_s)
        return p_sum[i];

    if (s == target_s && s == e) {
        return p_sum[i] = val % 2 ? 1 : 0;
    }

    int mid = s + (e - s) / 2;
    return p_sum[i] = update(i * 2, s, mid, target_s, val) +
                      update(i * 2 + 1, mid + 1, e, target_s, val);
}

int main() {
    input();
    set_tree(1, 1, N);

    cin >> M;
    for (int i = 0; i < M; i++) {
        int com;
        cin >> com;

        long long a, b;
        cin >> a >> b;
        if (com == 1) {
            update(1, 1, N, a, b);
        } else if (com == 2) {
            int num = b - a + 1;
            cout << num - get_sum(1, 1, N, a, b) << '\n';
        } else {
            cout << get_sum(1, 1, N, a, b) << '\n';
        }
    }

    return 0;
}