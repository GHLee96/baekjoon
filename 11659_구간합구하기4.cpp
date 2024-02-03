#include <iostream>

using namespace std;

int N, M;
int p_sum[100005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    int sum = 0;
    for (int i = 1; i <= N; i++) {
        int a;
        cin >> a;

        sum += a;
        p_sum[i] = sum;
    }

    for (int j = 0; j < M; j++) {
        int a, b;
        cin >> a >> b;

        cout << p_sum[b] - p_sum[a - 1] << '\n';
    }

    return 0;
}