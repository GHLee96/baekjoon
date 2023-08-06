#include <iostream>
#include <vector>

using namespace std;

int N, S;
vector<int> v;
int cnt;

void sol(int idx, int sum) {
    if (idx >= N) {
        if (sum == S) cnt++;
        return;
    }

    sol(idx + 1, sum);
    sol(idx + 1, sum + v[idx]);

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> S;
    v.resize(N);
    for (int i = 0; i < N; i++) cin >> v[i];

    sol(0, 0);

    if (S == 0) cnt--;
    cout << cnt;
    return 0;
}