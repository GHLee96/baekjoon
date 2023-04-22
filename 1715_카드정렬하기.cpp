#include <iostream>
#include <queue>
#include <vector>

using namespace std;
vector<int> v;
int N;

int solution() {
    priority_queue<int, vector<int>, greater<int>> q;

    for (int i = 0; i < N; i++) q.push(v[i]);

    int sum = 0;
    while (q.size() > 1) {
        int min_value = q.top();
        q.pop();
        int value = q.top();
        q.pop();
        sum += min_value + value;
        q.push(min_value + value);
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    v.resize(N);
    for (int i = 0; i < N; i++) cin >> v[i];

    cout << solution();

    return 0;
}