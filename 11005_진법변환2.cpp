#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, B;

    cin >> N >> B;

    int n;
    vector<int> v;

    n = N;
    while (n >= B) {
        v.push_back(n % B);
        n /= B;
    }
    v.push_back(n);
    reverse(v.begin(), v.end());

    for (const auto &item : v) {
        if (item >= 10) {
            cout << (char)('A' + item - 10);
        } else {
            cout << item;
        }
    }

    return 0;
}