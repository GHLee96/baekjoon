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

        if (less_pq.empty()) {
            less_pq.push(num);
        } else if (less_pq.size() > greater_pq.size()) {
            greater_pq.push(num);
        } else {
            less_pq.push(num);
        }

        if (!less_pq.empty() && !greater_pq.empty()) {
            if (less_pq.top() > greater_pq.top()) {
                int top_a = less_pq.top();
                int top_b = greater_pq.top();
                less_pq.pop();
                greater_pq.pop();

                less_pq.push(top_b);
                greater_pq.push(top_a);
            }
        }

        cout << less_pq.top() << "\n";
    }

    return 0;
}