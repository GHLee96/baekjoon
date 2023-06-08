#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int l = 0;
    int r = n - 1;
    int min_val = 0x7fffffff;

    int res_l;
    int res_r;

    while (l < r) {
        int diff = abs(v[l] + v[r]);
        if (min_val > diff) {
            min_val = diff;
            res_l = v[l];
            res_r = v[r];
        }
        if (v[l] + v[r] > 0) {
            r--;
        } else {
            l++;
        }
    }

    cout << res_l << " " << res_r;

    return 0;
}