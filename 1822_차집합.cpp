#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

set<int> s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int A, B;

    cin >> A >> B;
    for (int i = 0; i < A; i++) {
        int n;
        cin >> n;

        s.insert(n);
    }

    for (int i = 0; i < B; i++) {
        int n;
        cin >> n;

        s.erase(n);
    }

    cout << s.size() << '\n';
    for (auto x : s) {
        cout << x << ' ';
    }

    return 0;
}