#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool sol(string s, vector<string> &wordList) {
    int n = s.length();
    int m = wordList.size();

    vector<bool> dp(n + 1, false);
    dp[0] = true;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            int wordLen = wordList[j].length();
            if (i >= wordLen && dp[i - wordLen]) {
                string subStr = s.substr(i - wordLen, wordLen);
                if (subStr == wordList[j]) {
                    dp[i] = true;
                    break;
                }
            }
        }
    }

    return dp[n];
}

int main() {
    string s;
    cin >> s;

    int N;
    cin >> N;

    vector<string> wordList(N);
    for (int i = 0; i < N; i++) {
        cin >> wordList[i];
    }

    cout << sol(s, wordList);

    return 0;
}
