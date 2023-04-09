// #include <iostream>
// #include <vector>

// using namespace std;

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
//     int N, W, x, y;
//     cin >> N >> W;

//     int dp[N + 1][N + 1];
//     int dis[N];
//     int sum = 0;
//     vector<pair<int, int>> cur_cop1;
//     vector<pair<int, int>> cur_cop2;

//     cur_cop1.push_back(make_pair(1, 1));
//     cur_cop2.push_back(make_pair(N, N));

//     for (int i = 0; i < W; i++) {
//         cin >> x >> y;

//         int dis1, dis2;
//         for (int j = 0; j < cur_cop1.size(); j++) {
//             dis1 = abs(cur_cop1[j].first + cur_cop1[j].second - x - y);
//         }

//         for (int j = 0; j < cur_cop2.size(); j++) {
//             dis2 = abs(cur_cop1[j].first + cur_cop2[j].second - x - y);
//         }

//         if (dis1 == dis2) {
//                 }

//         dis[i] = min(dis1, dis2);
//         sum += dis[i];

//         if (N - x + N - y > x - 1 + y - 1) {
//             dis[i] = 1;
//         } else {
//             dis[i] = 2;
//         }
//     }

//     cout << sum << "\n";
//     for (int i = 0; i < W; i++) {
//         cout << dis[i] << "\n";
//     }

//     return 0;
// }

#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

int row, col;
vector<pair<int, int>> pathA;
vector<pair<int, int>> pathB;

int num;
int cache[1009][1009];

vector<int> v;

int getMaxDistance(int A, int B) {
    // 모든 사건 해결
    if (A == num || B == num) return 0;

    int& ret = cache[A][B];

    if (ret != -1) return ret;

    ret = 987654321;

    // 다음 사건 번호
    int maxLocation = max(A, B) + 1;

    // 경찰차 A 가 다음 사건 해결 시 이동 거리
    int distA = abs(pathA[maxLocation].first - pathA[A].first) +
                abs(pathA[maxLocation].second - pathA[A].second);

    // 경찰차 B 가 다음 사건 해결 시 이동 거리
    int distB = abs(pathB[maxLocation].first - pathB[B].first) +
                abs(pathB[maxLocation].second - pathB[B].second);

    // 경찰차 A 가 다음 사건을 해결하거나, B 가 다음 사건을 해결하거나
    int ret1 = getMaxDistance(maxLocation, B) + distA;
    int ret2 = getMaxDistance(A, maxLocation) + distB;

    return ret = min(ret1, ret2);
}

void reconstruct(int A, int B) {
    printf("(%d, %d) ", A, B);
    if (A == num || B == num) return;

    // 다음 사건 번호
    int maxLocation = max(A, B) + 1;

    int distA = abs(pathA[maxLocation].first - pathA[A].first) +
                abs(pathA[maxLocation].second - pathA[A].second);

    int distB = abs(pathB[maxLocation].first - pathB[B].first) +
                abs(pathB[maxLocation].second - pathB[B].second);

    int ret1 = getMaxDistance(maxLocation, B) + distA;
    int ret2 = getMaxDistance(A, maxLocation) + distB;

    // 현재 상태에서 경찰차 A 가 다음 사건을 해결할 때의 이동 경로가 더 길다면
    if (ret1 > ret2) {
        // 경찰차 B 가 다음 사건을 해결
        cout << 2 << endl;
        reconstruct(A, maxLocation);
    } else {
        cout << 1 << endl;
        reconstruct(maxLocation, B);
    }
}

void solve() {
    cout << getMaxDistance(0, 0) << endl;
    reconstruct(0, 0);
}

int main() {
    cin >> row;
    col = row;
    cin >> num;

    memset(cache, -1, sizeof(cache));

    // 처음 경찰차의 좌표
    pathA.push_back({1, 1});
    pathB.push_back({row, row});

    for (int i = 0; i < num; i++) {
        int x, y;
        cin >> x >> y;
        pathA.push_back({x, y});
        pathB.push_back({x, y});
    }

    solve();

    return 0;
}