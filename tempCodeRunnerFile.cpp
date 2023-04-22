#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    priority_queue<int, vector<int>, greater<int>> greater_pq;
    priority_queue<int> less_pq;

    // 10^5
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;

        if (!less_pq.empty()) {
            if (less_pq.top() < num) {
                greater_pq.push(num);
            } else {
                less_pq.push(num);
            }
        } else {
            less_pq.push(num);
        }

        while (less_pq.size() < greater_pq.size()) {
            less_pq.push(greater_pq.top());
            greater_pq.pop();
        }
        cout << less_pq.top() << "\n";
    }

    return 0;
}