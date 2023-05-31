#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

const int MOD = 822539;

vector<int> prime;
vector<pair<int, int>> my_hash[MOD];

bool is_prime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

void make_prime() {
    int cnt = 0;
    for (int i = 0; i < 100000; i++) {
        if (is_prime(i)) {
            prime.push_back(i);
            cnt++;
        }
        if (cnt == 26 * 2 + 1) break;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string str1, str2;
    int res = 0;

    cin >> str1 >> str2;

    int len_str1 = str1.length();
    int len_str2 = str2.length();

    make_prime();

    int max_window = min(len_str1, len_str2);
    for (int i = 1; i <= max_window; i++) {
        int key1 = 1;
        int key2 = 1;

        for (int j = 0; j < i; j++) {
            key1 = (key1 * prime[str1[j] - 'a']) % MOD;
            key2 = (key2 * prime[str1[j] - 'a' + 26]) % MOD;
        }

        int s = 0;
        int e = i - 1;

        while (e < len_str1) {
            my_hash[key1].push_back({key2, i});

            if (++e == len_str1) break;
            key1 = (key1 * prime[str1[e] - 'a']) % MOD;
            key1 = (key1 / prime[str1[s] - 'a']) % MOD;

            key2 = (key2 * prime[str1[e] - 'a' + 26]) % MOD;
            key2 = (key2 / prime[str1[s] - 'a' + 26]) % MOD;
            s++;
        }
    }

    for (int i = 1; i <= max_window; i++) {
        int key1 = 1;
        int key2 = 1;

        for (int j = 0; j < i; j++) {
            key1 = (key1 * prime[str2[j] - 'a']) % MOD;
            key2 = (key2 * prime[str2[j] - 'a' + 26]) % MOD;
        }

        int s = 0;
        int e = i - 1;

        while (e < len_str2) {
            for (auto x : my_hash[key1]) {
                if (x == make_pair(key2, i)) {
                    res = max(res, i);
                }
            }

            if (++e == len_str2) break;
            key1 = (key1 * prime[str2[e] - 'a']) % MOD;
            key1 = (key1 / prime[str2[s] - 'a']) % MOD;

            key2 = (key2 * prime[str2[e] - 'a' + 26]) % MOD;
            key2 = (key2 / prime[str2[s] - 'a' + 26]) % MOD;
            s++;
        }
    }

    cout << res;
}
