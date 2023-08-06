#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    priority_queue<int, vector<int>, greater<int>> q;

    int n;
    int op;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> op;

        if (op == 0) {
            if (q.empty())
                cout << "0\n";
            else {
                cout << q.top() << "\n";
                q.pop();
            }
        } else {
            q.push(op);
        }
    }
    return 0;
}