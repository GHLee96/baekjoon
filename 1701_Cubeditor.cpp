#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

vector<int> pi;

void get_pi(string P) {
    int p_len = P.length();
    int j = 0;

    pi.resize(p_len, 0);
    for (int i = 1; i < p_len; i++) {
        while (j > 0 && P[i] != P[j]) j = pi[j - 1];
        if (P[i] == P[j]) pi[i] = ++j;
    }
}

bool kmp(string T, string P) {
    get_pi(P);
    int n = T.length();
    int m = P.length();
    int j = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        while (j > 0 && T[i] != P[j]) j = pi[j - 1];
        if (T[i] == P[j]) {
            if (j == m - 1) {
                cnt++;
                if (cnt > 1) return true;
            } else {
                j++;
            }
        }
    }
    return false;
}

int main() {
    string T, P;

    cin >> T;
    int len = T.length();
    int ans = 0;

    for (int i = 0; i < len; i++) {
        P = T.substr(i);
        if (kmp(T, P)) {
            ans = max(ans, len - i);
        }
    }

    cout << ans << endl;

    return 0;
}