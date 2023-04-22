/* #include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    vector<int> answer(n, -1);
    stack<int> st;  // 스택에 인덱스 저장

    for (int i = 0; i < n; ++i) {
        while (!st.empty() && arr[st.top()] < arr[i]) {
            answer[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }

    for (auto ans : answer) {
        cout << ans << ' ';
    }
    cout << '\n';

    return 0;
} */

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> ans(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;  // (value, index)

    for (int i = 0; i < n; i++) {
        while (!pq.empty()) {
            int value = pq.top().first;
            int index = pq.top().second;
            if (a[i] > value) {
                ans[index] = a[i];
                pq.pop();
            } else {
                break;
            }
        }
        pq.push(make_pair(a[i], i));
    }

    while (!pq.empty()) {
        int value = pq.top().first;
        int index = pq.top().second;
        ans[index] = -1;
        pq.pop();
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';

    return 0;
}
