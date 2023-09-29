#include <cstring>
#include <iostream>
using namespace std;

int arr[3];
int N;
int dp[65][65][65];

int sol(int a, int b, int c) {

    if (a < 0)
        return sol(0, b, c);
    if (b < 0)
        return sol(a, 0, c);
    if (c < 0)
        return sol(a, b, 0);

    if (a == 0 && b == 0 && c == 0)
        return 0;

    int &ret = dp[a][b][c];
    if (ret != -1)
        return ret;

    ret = 0x7fffffff;

    ret = min(ret, sol(a - 9, b - 3, c - 1) + 1);
    ret = min(ret, sol(a - 9, b - 1, c - 3) + 1);
    ret = min(ret, sol(a - 3, b - 9, c - 1) + 1);
    ret = min(ret, sol(a - 3, b - 1, c - 9) + 1);
    ret = min(ret, sol(a - 1, b - 3, c - 9) + 1);
    ret = min(ret, sol(a - 1, b - 9, c - 3) + 1);

    return ret;
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    memset(dp, -1, sizeof(dp));
    cout << sol(arr[0], arr[1], arr[2]);

    return 0;
}