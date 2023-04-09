// https://degurii.tistory.com/158

#include <iostream>

#define MAX 55

using namespace std;

long long power2[MAX];
long long A, B;

long long getOne(long long x) {
    long long ret = x & 1;

    for (int i = MAX - 1; i > 0; i--) {
        if (x & (1LL << i)) {
            ret += power2[i - 1] + (x - (1LL << i) + 1);
            x -= 1LL << i;
        }
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> A >> B;

    power2[0] = 1;
    for (int i = 1; i < MAX; i++) {
        power2[i] = 2 * power2[i - 1] + (1LL << i);
    }

    cout << getOne(B) - getOne(A - 1);

    return 0;
}

/* #include <math.h>

#include <iostream>

#define MASK 0xffffffffffffff
using namespace std;

long long dp[55] = {
    0,
};

int main() {
    long long A, B;
    cin >> A >> B;

    dp[0] = 0;
    long long add = 1;
    for (long long i = 1; i < A; i++) {
        dp[i] = dp[i - 1] * 2 + 1 * add;
        add *= 2;
    }

    long long sub_A = 0;
    for (int i = 55; i >= 0; i--) {
        if ((A >> i) & 0x01) {
            sub_A = i;
            break;
        }
    }

    int a = 0;
    for (int i = sub_A - 1; i >= 0; i--) {
        if ((A >> i) & 0x01) {
            a = i;
            break;
        }
    }

    long long upp_A =
        dp[a] + (A - pow(2, sub_A) + 1) + (A - pow(2, sub_A) - pow(2, a) + 1);

    if ((A >> a) & 1) upp_A++;

    cout << dp[a]

         << (A - pow(2, sub_A) - pow(2, a) + 1);

    int sub_B = 0;
    for (int i = 55; i >= 0; i--) {
        if ((B >> i) & 0x01) {
            sub_B = i;
            break;
        }
    }

    return 0;
} */

/*
    4 8/8 12/8 12 12 16/8 12 12 16 12 16 16 20/

    00 0
    01 1
    10 1
    11 2  +0

    -------------
    100 1
    101 2
    110 2
    111 3   +4

    -----------
    1000 1
    1001 2
    1010 2
    1011 3   +4

    1100 2
    1101 3
    1110 3   +8
    1111 4
    -----------
    10000+4
    10100+8

    11000+8
    11100+12

    ------------
    100000 +4
    100100 +8
    101000 +8
    101100 +12

    110000 +8
    110100 +12
    111000 +12
    111100 +16

    ------------
    1000000 +4
    1000100
    1001000
    1001100
    1010000
    1010100
    101

*/