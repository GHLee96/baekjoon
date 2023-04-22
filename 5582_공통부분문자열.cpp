#include <cstring>
#include <iostream>

using namespace std;

int dp[4001][4001] = {
    0,
};

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    int size_s1 = s1.size();
    int size_s2 = s2.size();

    int result = 0;
    for (int i = 0; i < size_s2; i++) {
        for (int j = 0; j < size_s1; j++) {
            if (s1[j] == s2[i]) {
                dp[i][j] = 1;
                if (i >= 1 && j >= 1) {
                    dp[i][j] += dp[i - 1][j - 1];  // 완전 탐색 이지만 값을 dp로
                    result = max(result, dp[i][j]);
                }
            }
        }
    }
    cout << result;

    return 0;
}