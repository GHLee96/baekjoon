#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

string dp[10005];

string addStrings(string num1, string num2) {
    string result;
    int carry = 0;

    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());

    while (num1.length() < num2.length()) {
        num1 += '0';
    }
    while (num1.length() > num2.length()) {
        num2 += '0';
    }

    for (int i = 0; i < num1.length(); ++i) {
        int num = (num1[i] - '0' + num2[i] - '0' + carry) % 10;
        result += to_string(num);
        carry = (num1[i] - '0' + num2[i] - '0' + carry) / 10;
    }
    if (carry != 0) {
        result += to_string(carry);
    }

    reverse(result.begin(), result.end());

    return result;
}

string fibonacci(int n) {
    if (n == 0)
        return "0";
    if (n == 1)
        return "1";

    dp[0] = "0";
    dp[1] = "1";

    for (int i = 2; i <= n; i++) {
        dp[i] = addStrings(dp[i - 1], dp[i - 2]);
    }

    return dp[n];
}

int main() {
    int n;
    cin >> n;

    cout << fibonacci(n) << endl;

    return 0;
}