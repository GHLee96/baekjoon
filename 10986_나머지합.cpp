#include <iostream>
#include <vector>

using namespace std;

vector<long long> rv;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    long long sum = 0;
    cin >> N >> M;
    rv.resize(M, 0);

    for (int i = 0; i < N; i++) {
        int value;
        cin >> value;
        sum += value;
        rv[sum % M]++;
    }

    long long cnt = rv[0];
    for (auto x : rv) {
        cnt += x * (x - 1) / 2;
    }

    cout << cnt;

    return 0;
}