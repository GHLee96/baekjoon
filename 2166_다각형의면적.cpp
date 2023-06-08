#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    double sum = 0;
    cin >> n;

    vector<long long> x(n + 1);
    vector<long long> y(n + 1);

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    x[n] = x[0];
    y[n] = y[0];

    for (int i = 0; i < n; i++) {
        sum += x[i] * y[i + 1] - x[i + 1] * y[i];
    }

    sum = abs(sum) / 2;

    cout << fixed;
    cout.precision(1);
    cout << sum;

    return 0;
}