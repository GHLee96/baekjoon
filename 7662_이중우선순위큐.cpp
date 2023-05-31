#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// struct Info {
//     int n, i;
// };

// struct cmp1 {
//     bool operator()(const Info& a, const Info& b) { return a.n < b.n; }
// };

// struct compare {
//     bool operator()(const Info& a, const Info& b) { return a.n > b.n; }
// };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;

    int n, k;
    char op;
    for (int i = 0; i < T; i++) {
        cin >> k;

        priority_queue<pair<int, int>> lq;
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            gq;
        int size = 0;

        int check[1000001] = {
            0,
        };

        for (int j = 0; j < k; j++) {
            cin >> op >> n;

            if (op == 'I') {
                lq.push({n, j});
                gq.push({n, j});
                size++;
            } else if (op == 'D') {
                if (size == 0) continue;

                if (n == 1) {
                    while (!lq.empty() && check[lq.top().second] == 1) {
                        lq.pop();
                    }
                    check[lq.top().second] = 1;
                    lq.pop();

                } else if (n == -1) {
                    while (!gq.empty() && check[gq.top().second] == 1) {
                        gq.pop();
                    }
                    check[gq.top().second] = 1;
                    gq.pop();
                }
                size--;
            }
        }

        while (!lq.empty() && check[lq.top().second] == 1) {
            lq.pop();
        }
        while (!gq.empty() && check[gq.top().second] == 1) {
            gq.pop();
        }

        if (size == 0)
            cout << "EMPTY\n";
        else
            cout << lq.top().first << " " << gq.top().first << '\n';
    }
    return 0;
}