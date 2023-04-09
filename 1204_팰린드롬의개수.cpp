#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

const int MOD = 835454957;

int main() {
    int n, k;
    cin >> n >> k;
    vector<string> words(n);
    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }

    vector<vector<int>> dp(k + 1, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        dp[words[i].size()][i] = 1;
    }

    for (int len = 1; len <= k; len++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int newLen = len - words[i].size() - words[j].size() - 1;
                if (newLen < 0) {
                    continue;
                }
                dp[len][i] = (dp[len][i] + dp[newLen][j]) % MOD;
            }
        }
    }

    int ans = 0;
    for (int len = 1; len <= k; len++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                string s = words[i] + " " + words[j];
                int left = 0, right = s.size() - 1;
                bool isPalindrome = true;
                while (left < right) {
                    while (left < right && s[left] == ' ') {
                        left++;
                    }
                    while (left < right && s[right] == ' ') {
                        right--;
                    }
                    if (s[left] != s[right]) {
                        isPalindrome = false;
                        break;
                    }
                    left++;
                    right--;
                }
                if (isPalindrome) {
                    ans = (ans + dp[k - len][i] * dp[len][j]) % MOD;
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}
