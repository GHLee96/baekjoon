#include <iostream>
#include <vector>

using namespace std;

int n;  // 기관차의 객차수
int tr_size;
vector<vector<int>> dp;
vector<int> sum;
const int TR_NUM = 3;

int solution(int tr, int i) {
    if (tr == TR_NUM + 1 || i + tr_size > n) return 0;

    int &ret = dp[tr][i];
    if (ret != -1) return ret;

    ret = max(solution(tr, i + 1),
              solution(tr + 1, i + tr_size) + sum[i + tr_size] - sum[i]);

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);

    vector<int> arr;
    vector<int> tr_sum;
    int max_res = 0;

    cin >> n;
    arr.resize(n + 1);
    sum.resize(n + 1);
    tr_sum.resize(n);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    cin >> tr_size;

    dp.resize(TR_NUM + 1, vector<int>(n + 1, -1));
    for (int i = 1; i <= n; i++) {
        sum[i] = arr[i] + sum[i - 1];
    }

    cout << solution(1, 0);
    // vector<vector<int>> dp(TR_NUM, vector<int>(n));
    // for (int i = 0; i < TR_NUM; i++) {
    //     for (int j = (i + 1) * tr_size - 1; j < n; j++) {
    //         if (i == 0)
    //             dp[i][j] = max(dp[i][j - 1], sum[j] - sum[j - tr_size]);
    //         else
    //             dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - tr_size] + sum[j]
    //             -
    //                                              sum[j - tr_size]);
    //     }
    // }
    // cout << dp[TR_NUM - 1][n - 1];

    // for (int i = 0; i <= n - tr_size * (TR_NUM - 2); i++) {
    //     if (i == 0) tr_sum[i] = sum[i + tr_size - 1];
    //     tr_sum[i + 1] = sum[i + tr_size] - sum[i];
    // }

    // vector<int> dp(n, 0);
    // for (int i = n - tr_size; i >= 0; i--) {
    //     dp[i] = max(dp[i + 1], tr_sum[i]);
    // }

    // vector<int> r_dp(n, 0);
    // for (int i = tr_size; i < n; i++) {
    //     if (i == tr_size) r_dp[i] = tr_sum[i - tr_size];
    //     r_dp[i] = max(r_dp[i - 1], tr_sum[i - tr_size]);
    // }

    // for (int i = tr_size; i <= n - tr_size * (TR_NUM - 1); i++) {
    //     max_res = max(max_res, r_dp[i] + dp[i + tr_size] + tr_sum[i]);
    // }

    // cout << max_res;
    return 0;
}