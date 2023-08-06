#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int n;
vector<int> v;
vector<int> table;

void LIS() {
    vector<int> res;

    int res_idx = 0;
    for (int i = 0; i < n; i++) {
        int x = v[i];

        auto pos = lower_bound(res.begin(), res.end(), x);
        if (pos == res.end()) {
            res.push_back(x);
            table[i] = res_idx++;
        } else {
            int idx = pos - res.begin();
            res[idx] = x;
            table[i] = idx;
        }
    }

    cout << res.size() << "\n";

    res_idx = res.size() - 1;

    stack<int> st;
    for (int i = n - 1; i >= 0; i--) {
        if (table[i] == res_idx) {
            st.push(v[i]);
            res_idx--;
        }
    }

    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    v.resize(n);
    table.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    LIS();

    return 0;
}