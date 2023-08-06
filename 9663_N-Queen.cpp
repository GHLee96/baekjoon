#include <iostream>

using namespace std;

int N;

bool col[14];
bool row[14];
bool left_up[14];
bool right_up[30];

int cnt;

int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

void sol(int r) {
    if (r == N) {
        cnt++;
        return;
    }

    for (int c = 0; c < N; c++) {
        int left_i = r + c;
        int right_i = c - r + N;

        if (col[c]) continue;
        if (left_up[left_i]) continue;
        if (right_up[right_i]) continue;

        col[c] = true;
        left_up[left_i] = true;
        right_up[right_i] = true;

        sol(r + 1);

        col[c] = false;
        left_up[left_i] = false;
        right_up[right_i] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    sol(0);

    cout << cnt;
    return 0;
}