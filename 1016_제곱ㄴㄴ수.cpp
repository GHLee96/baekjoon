#include <math.h>

#include <iostream>
#include <vector>

using namespace std;

long long input_min, input_max;

vector<long long> check;

int get_square() {
    long long limit = sqrt(input_max);
    for (long long i = 2; i <= limit; i++) {
        long long q = input_min / (i * i);
        long long r = input_min % (i * i);

        long long j = r != 0 ? (i * i) * (++q) : j = (i * i) * q;

        while (j <= input_max) {
            check[j - input_min] = 1;
            j = i * i * ++q;
        }
    }

    int cnt = 0;
    for (long long i = 0; i < input_max - input_min + 1; i++) {
        if (check[i] == 0) cnt++;
    }

    return cnt;
}

void input() {
    cin >> input_min >> input_max;
    check.resize(input_max - input_min + 1, 0);
}

int main() {
    input();
    cout << get_square();

    return 0;
}