#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;

    queue<int> q;
    for (int i = 1; i <= n; i++) q.push(i);

    int cnt = 0;
    while (q.size() > 1) {
        if (cnt++ % 2 == 0) {
            q.pop();
        } else {
            q.push(q.front());
            q.pop();
        }
    }
    cout << q.front();
    return 0;
}