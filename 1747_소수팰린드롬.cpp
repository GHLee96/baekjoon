#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int a;

int p[2000005];
vector<int> prime;

void make_prime() {
    p[0] = 1;
    p[1] = 1;

    for (int i = 2; i < 2000005; i++) {
        if (p[i])
            continue;

        prime.push_back(i);
        for (int j = i * 2; j < 2000005; j += i) {
            p[j] = 1;
        }
    }
}

int is_palindrome(int n) {
    string str = to_string(n);

    int l = 0;
    int r = str.size() - 1;

    while (l < r) {
        if (str[l++] != str[r--])
            return 0;
    }

    return 1;
}

int main() {
    cin >> a;

    make_prime();
    sort(prime.begin(), prime.end());

    for (int i = 0; i < prime.size(); i++) {
        if (prime[i] < a)
            continue;

        if (is_palindrome(prime[i])) {
            cout << prime[i] << '\n';
            break;
        }
    }

    return 0;
}
