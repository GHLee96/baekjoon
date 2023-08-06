#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        q;

    int n;
    int op;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> op;

        if (op == 0) {
            if (q.empty())
                cout << "0\n";
            else {
                cout << q.top().second << "\n";
                q.pop();
            }
        } else {
            q.push({abs(op), op});
        }
    }
    return 0;
}