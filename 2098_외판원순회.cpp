#include <bitset>
#include <iostream>
#define INF 0x7fffffff

using namespace std;

int N;
int W[16][16];
int dp[16][1 << 16] = {
    0,
};

int TSP(int city, int visited) {
    if (visited == (1 << N) - 1) {
        if (W[city][0] == 0)
            return INF;  // 마지막 도시에서 출발 지점으로 가지 못할 때
        return W[city][0];
    }
    int &ret = dp[city][visited];
    if (ret != 0) return ret;
    ret = INF;

    for (int i = 0; i < N; i++) {
        if (W[city][i] == 0) continue;
        if (visited & (1 << i)) continue;

        int tsp = TSP(i, visited | (1 << i));
        if (tsp == INF) continue;  // 불가능한 경우 제외
        ret = min(ret, W[city][i] + tsp);
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> W[i][j];
        }
    }

    cout << TSP(0, 1 << 0);

    return 0;
}