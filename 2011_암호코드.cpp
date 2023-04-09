#include <iostream>
#include <string>
#define MOD 1000000

using namespace std;

int main() {
    string str;
    cin >> str;

    int len = str.size();

    int dp[5001] = {
        0,
    };

    if (str[0] == '0') {
        cout << "0";
        return 0;
    } else {
        dp[0] = 1;
    }

    int value = ((str[0] - '0') * 10 + str[1] - '0');
    if (value <= 26) {
        if (str[1] == '0') {
            dp[1] = dp[0];
        } else {
            dp[1] = dp[0] + 1;
        }
    } else {
        if (str[1] == '0') {
            cout << "0";
            return 0;
        } else {
            dp[1] = dp[0];
        }
    }

    for (int i = 2; i < len; i++) {
        value = ((str[i - 1] - '0') * 10 + str[i] - '0');

        if (value <= 26) {
            if (str[i] == '0') {
                if (str[i - 1] == '0') {
                    cout << 0;
                    return 0;
                } else {
                    dp[i] = dp[i - 2];
                }
            } else {
                if (str[i - 1] == '0') {
                    dp[i] = dp[i - 1];
                } else {
                    dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
                }
            }
        } else {
            if (str[i] == '0') {
                cout << "0";
                return 0;
            }
            dp[i] = dp[i - 1];
        }
        // cout << dp[i] << " ";
    }

    cout << dp[len - 1];

    return 0;
}

/*
#include <iostream>
#include <vector>

using namespace std;
const int MOD = 1e6; //모듈러 연산 상수
int dp[5001]={0,};
int solution(string code, int n ) {
        if(code[0]=='0') return 0;
        dp[0]=dp[1]=1;

        for(int i=2;i<=n;i++){
                if(code[i-1]!='0') dp[i]=dp[i-1]%MOD;

                int tmp=(code[i-2]-'0')*10+(code[i-1]-'0');
                if(tmp>=10&&tmp<=26)
                        dp[i]=(dp[i]+dp[i-2])%MOD;
        }

    return dp[n];
}

int main() {
    string str;
    cin >> str;
    int answer = solution(str, str.length());
    cout << answer;
    return 0;
}
*/