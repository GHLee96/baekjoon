#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> arr[4];
int N;

int s1[4005 * 4005];
int s2[4005 * 4005];

void input() {
    cin >> N;

    for (int i = 0; i < 4; i++)
        arr[i].resize(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> arr[j][i];
        }
    }
}

void solution() {
    int idx = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int sum = arr[0][i] + arr[1][j];

            s1[idx++] = sum;
        }
    }

    idx = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int sum = arr[2][i] + arr[3][j];

            s2[idx++] = sum;
        }
    }

    sort(s1, s1 + idx);
    sort(s2, s2 + idx);
    long long cnt = 0;

    for (int i = 0; i < idx; i++) {
        int target = -s1[i];

        auto l = lower_bound(s2, s2 + idx, target);
        auto r = upper_bound(s2, s2 + idx, target);

        cnt += r - l;
    }
    cout << cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    solution();

    return 0;
}