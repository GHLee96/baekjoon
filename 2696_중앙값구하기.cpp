#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;

        priority_queue<int> q1;
        priority_queue<int, vector<int>, greater<int>> q2;

        cout << N / 2 + 1 << '\n';
        for (int i = 0; i < N / 2 + 1; i++) {
            for (int k = 0; k < 2; k++) {
                int a;
                cin >> a;
                if (i == 0) {
                    q1.push(a);
                    break;
                }
                if (a < q1.top()) {
                    q1.push(a);
                } else {
                    q2.push(a);
                }
            }
            while (q1.size() > q2.size() + 1) {
                q2.push(q1.top());
                q1.pop();
            }

            while (q1.size() < q2.size() + 1) {
                q1.push(q2.top());
                q2.pop();
            }

            cout << q1.top() << ' ';
        }
        cout << '\n';
    }

    return 0;
}