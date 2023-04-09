#include <math.h>

#include <cstring>
#include <iostream>
#include <vector>

#define INF 0x7fffffff

using namespace std;
long long dp[101];

/*
    1 2 3 4 5 6 7 8 9 0
    2 5 5 4 5 6 3 7 6 6
*/
string solution_max(int n) {
    long long max = 0;
    int even;
    if (n == 3) return "7";
    if (n % 2 == 1) {
        even = (n - 3);
    } else {
        // 짝수일 때, 모두 1로 바꾼다.
        even = n;
    }

    string ans = "1";
    int mod = even / 2;
    for (int i = 1; i < mod; i++) {
        ans = "1" + ans;
    }

    if (n % 2 == 1) {
        ans = "7" + ans;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, 0x7f, sizeof(dp));

    dp[2] = 1;
    dp[3] = 7;
    dp[4] = 4;
    dp[5] = 2;
    dp[6] = 6;
    dp[7] = 8;
    dp[8] = 10;

    for (int i = 9; i <= 100; i++) {
        for (int j = 2; j <= 7; j++) {
            int units = dp[j];
            if (j == 6) units = 0;

            dp[i] = min(dp[i], dp[i - j] * 10 + units);
        }
    }

    int T, n, test_case;
    cin >> T;

    for (test_case = 1; test_case <= T; test_case++) {
        cin >> n;
        cout << dp[n] << " " << solution_max(n) << "\n";
    }

    return 0;
}
