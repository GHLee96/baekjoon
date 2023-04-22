/* #include <iostream>
using namespace std;

const int MOD = 1000000000;

int main() {
    int dp[201][201];

    int N, K;
    cin >> N >> K;

    // 초기값 설정
    for (int i = 0; i <= N; i++) {
        dp[i][1] = 1;
    }

    // dp 배열 계산
    for (int j = 2; j <= K; j++) {
        for (int i = 0; i <= N; i++) {
            dp[i][j] = 0;
            for (int k = 0; k <= i; k++) {
                dp[i][j] += dp[k][j - 1];
                dp[i][j] %= MOD;
                // printf("%d", dp[k][j - 1]);
            }
            // printf("     %d \n", dp[i][j]);
        }
    }

    // 답 출력
    cout << dp[N][K] << endl;

    return 0;
} */

/* #include <iostream>
using namespace std;

const int MOD = 1000000000;
int dp[201][201];

int solve(int n, int k) {
    // 이전에 계산한 값이 있다면 그 값을 반환
    if (dp[n][k] != -1) {
        return dp[n][k];
    }

    // 기저 사례: k가 1인 경우
    if (k == 1) {
        return 1;
    }

    int sum = 0;
    for (int i = 0; i <= n; i++) {
        sum += solve(n - i, k - 1);
        sum %= MOD;
    }

    // 계산한 값을 메모리에 저장
    dp[n][k] = sum;

    return sum;
}

int main() {
    int N, K;
    cin >> N >> K;

    // DP 테이블 초기화
    memset(dp, -1, sizeof(dp));

    // 답 출력
    cout << solve(N, K) << endl;

    return 0;
}
 */

#include <cstring>
#include <iostream>

#define MOD 1000000000

using namespace std;

int dp[201][201];

int solution(int n, int count) {
    if (count == 1) return 1;

    int &ret = dp[n][count];
    if (ret != -1) return ret;

    ret = 0;
    for (int i = 0; i <= n; i++) {
        ret += solution(i, count - 1);
        ret %= MOD;
    }

    return ret;
}

int main() {
    memset(dp, -1, sizeof(dp));
    int N, K;
    cin >> N >> K;
    cout << solution(N, K);

    return 0;
}