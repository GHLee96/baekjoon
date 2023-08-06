#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> dp;
vector<int> v;
// vector<vector<int>> pre;
vector<int> idx_map;

void LIS(vector<int>& v) {
    int i = 0;
    for (auto x : v) {
        auto it = lower_bound(dp.begin(), dp.end(), x);
        int idx = it - dp.begin();

        if (it == dp.end()) {
            // pre[idx].push_back(x);
            dp.push_back(x);
        } else {
            // if (pre[idx].size() == 0) pre[idx].push_back(*it);
            // pre[idx].push_back(x);
            *it = x;
        }
        idx_map[i++] = idx;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;

    cin >> n;
    v.resize(n);
    // pre.resize(n);
    idx_map.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    LIS(v);

    stack<int> st;

    cout << dp.size() << "\n";
    // st.push(pre[dp.size() - 1][0]);

    // for (int i = dp.size() - 2; i >= 0; i--) {
    //     for (auto x : pre[i]) {
    //         if (x < st.top()) {
    //             st.push(x);
    //             break;
    //         }
    //     }
    // }

    int idx = dp.size() - 1;

    for (int i = n - 1; i >= 0; i--) {
        if (idx == idx_map[i]) {
            st.push(v[i]);
            idx--;
        }
    }

    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}

/*
3 1 4 6 2 2 0 3 6
0 0 1 2 1 1 0 2 3

3
1
1 4
1 4 6
1 2 6
1 2 6
0 2 6
0 2 3
0 2 3 6
*/