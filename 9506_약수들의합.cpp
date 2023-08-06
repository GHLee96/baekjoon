#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int main() {
    int n = 0;
    while (1) {
        cin >> n;
        if (n == -1) break;

        int k = sqrt(n);
        vector<int> v;
        for (int i = 1; i <= k; i++) {
            if (!(n % i)) {
                v.push_back(i);
                v.push_back(n / i);
            }
        }

        sort(v.begin(), v.end());
        if (accumulate(v.begin(), v.end() - 1, 0) == n) {
            cout << n << " = ";
            for (int i = 0; i < v.size() - 1; i++) {
                cout << v[i];

                if (i < v.size() - 2) cout << " + ";
            }
        } else {
            cout << n << " is NOT perfect.";
        }
        cout << '\n';
    }
    return 0;
}