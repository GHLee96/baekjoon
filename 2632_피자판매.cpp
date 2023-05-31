#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int request_size;
int m, n;
vector<int> a;
vector<int> b;
vector<int> sum_a;
vector<int> sum_b;

void sol() {
    int sum;
    for (int i = 0; i < m; i++) {
        sum = 0;
        for (int j = i; j < i + m - 1; j++) {
            sum += a[j % m];
            sum_a[sum]++;
        }
    }
    sum = 0;
    for (auto x : a) sum += x;
    sum_a[sum]++;

    for (int i = 0; i < n; i++) {
        sum = 0;
        for (int j = i; j < i + n - 1; j++) {
            sum += b[j % n];
            sum_b[sum]++;
        }
    }
    sum = 0;
    for (auto x : b) sum += x;
    sum_b[sum]++;

    sum = 0;
    sum_a[0] = 1;
    sum_b[0] = 1;
    for (int i = 0; i <= request_size; i++) {
        sum += sum_a[i] * sum_b[request_size - i];
    }
    cout << sum;
}

void input() {
    cin >> request_size;
    cin >> m >> n;

    a.resize(m);
    b.resize(n);
    sum_a.resize(1000001);
    sum_b.resize(1000001);
    for (int i = 0; i < m; i++) cin >> a[i];
    for (int j = 0; j < n; j++) cin >> b[j];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    sol();

    return 0;
}