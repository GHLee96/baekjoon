#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int input;
    cin >> n;

    priority_queue<int> q;
    for (int i = 0; i < n; i++) {
        cin >> input;

        if (input == 0) {
            if (!q.empty()) {
                cout << q.top();
                q.pop();
            } else {
                cout << "0";
            }
            cout << "\n";
        } else {
            q.push(input);
        }
    }

    return 0;
}