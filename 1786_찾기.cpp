#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

vector<int> pi;
vector<int> ans;

void get_pi(string P) {
    int p_len = P.length();
    int j = 0;

    pi.resize(p_len, 0);
    for (int i = 1; i < p_len; i++) {
        while (j > 0 && P[i] != P[j]) j = pi[j - 1];
        if (P[i] == P[j]) pi[i] = ++j;
    }
}

void kmp(string T, string P) {
    get_pi(P);
    int n = T.length();
    int m = P.length();
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j > 0 && T[i] != P[j]) j = pi[j - 1];
        if (T[i] == P[j]) {
            if (j == m - 1) {
                ans.push_back(i - m + 1);
                j = pi[j];
            } else {
                j++;
            }
        }
    }
}

int main() {
    string T, P;

    getline(cin, T);
    getline(cin, P);
    kmp(T, P);
    cout << ans.size() << endl;
    for (auto x : ans) {
        cout << x + 1 << " ";
    }
    return 0;
}