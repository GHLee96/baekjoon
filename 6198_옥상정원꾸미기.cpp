#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    int arr[80001];
    stack<pair<int, int>> s;  // height, idx

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    long long res = 0;
    for (int i = 0; i < N; i++) {
        while (!s.empty() && arr[i] >= s.top().first) {
            res += i - s.top().second - 1;

            s.pop();
        }
        s.push({arr[i], i});
    }

    s.pop();
    while (!s.empty()) {
        res += N - 1 - s.top().second;
        s.pop();
    }

    cout << res;

    return 0;
}