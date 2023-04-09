#include <iostream>
#include <vector>

#define MOD 1'000'000'000

using namespace std;

int main() {
    int N;
    cin >> N;

    int dp[1000001] = {
        0,
    };

    vector<int> member;
    for (int j = 1; j <= N; j *= 2) {
        member.push_back(j);
    }

    dp[0] = 1;
    for (int i = 0; i < member.size(); i++) {
        for (int j = member[i]; j <= N; j++) {
            dp[j] = (dp[j] + dp[j - member[i]]) % MOD;
        }
    }
    /*
        1 2 4 8

        4 0 0
        2 1 0
        0 2 0
        0 0 1


        8 0 0
        4 2 0
        4 0 0
        6 1 0
        2 3 0
        2 1 1

        0 0 2
        0 4 0
        0 2 1
        0 0 0 1


        7 0 0
        5 1 0
        3 2 0
        1 3 0
        3 0 1
        1 1 1
     */

    /* for (int i = 1; i <= n; i++) {
        i % 2 ? memo[i] = (memo[i - 1]) % DIV
              : memo[i] = (memo[i - 1] + memo[i / 2]) % DIV;
    } */

    cout << dp[N];

    return 0;
}