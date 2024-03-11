#include <cstring>
#include <iostream>

using namespace std;

int cnt[50][2];
int visit[50];

void fibonacci(int n) {
    if (n == 0) {
        cnt[n][0]++;
        return;
    } else if (n == 1) {
        cnt[n][1]++;
        return;
    }

    if (!visit[n - 1]) {
        visit[n - 1] = 1;
        fibonacci(n - 1);
    }

    if (!visit[n - 2]) {
        visit[n - 2] = 1;
        fibonacci(n - 2);
    }

    cnt[n][0] = cnt[n - 2][0] + cnt[n - 1][0];
    cnt[n][1] = cnt[n - 2][1] + cnt[n - 1][1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T, n;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        cin >> n;

        memset(cnt, 0, sizeof(cnt));
        memset(visit, 0, sizeof(visit));

        fibonacci(n);

        cout << cnt[n][0] << ' ' << cnt[n][1] << '\n';
    }

    return 0;
}