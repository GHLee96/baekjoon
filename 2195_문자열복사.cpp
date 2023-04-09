
#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

#define INF 987654321

string A, B;

int N, M;

int dp[1001];

int solve(int idx) {
    if (idx == M) return 0;

    int &ret = dp[idx];

    if (ret != -1) return ret;

    ret = INF;
    /*
        for (int next = idx; next < M; next++) {
            if (A.find(B.substr(idx, next - idx + 1)) != string::npos)

                ret = min(ret, solve(next + 1) + 1);
        }
      */
    for (int n = 0; n < N; n++) {
        if (A[n] != B[idx]) continue;

        int cnt = 0;

        while (n + cnt < N && idx + cnt < M && A[n + cnt] == B[idx + cnt])
            cnt++;

        ret = min(ret, solve(idx + cnt) + 1);
    }

    printf("idx : %d, ret : %d\n", idx, ret);
    return ret;
}

int main() {
    memset(dp, -1, sizeof dp);

    ios::sync_with_stdio(false);

    cin >> A >> B;

    N = A.length(), M = B.length();

    cout << solve(0);

    return 0;
}

/* #include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int dp[1001] = {
    0,
};

int main() {
    string str1, str2;
    cin >> str1 >> str2;

    int result = 0;
    for (int i = 0; i < str2.size();) {
        int max = 0;

        for (int j = 0; j < str1.size(); j++) {
            int same_len = 0;

            while (str1[j + same_len] == str2[i + same_len]) same_len++;
            if (max < same_len) max = same_len;
        }
        i += max;
        result++;
    }

    cout << result;
    return 0;
} */