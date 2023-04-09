#include <iostream>

using namespace std;

int dp[1001] = {
    0,
};

/*
    a a a b a
    a b b b a
    a b a a a

    a a a b b b
    a b a b b b
    a b b b a b

    a a a b a a a
    a b a b a a a
    a b a a a b a
    a b b b a a a
    a b /a /b a a a
    a b /a /b b b a-
*/
int solution(int N) {
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 1;
    dp[4] = 2;
    for (int i = 5; i <= N; i++) {
        dp[i] = min(dp[i - 3] + 1, dp[i - 1] + 1);
    }

    return dp[N];
}

int main() {
    int N;
    cin >> N;

    if (solution(N) % 2 == 1)
        cout << "SK";
    else
        cout << "CY";

    return 0;
}