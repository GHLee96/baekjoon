#include <iostream>
#include <queue>
#include <stack>

using namespace std;
int x;

int pre[1000001];
const int dest = 1;

void find_route(int i) {
    stack<int> st;
    st.push(i);
    while (i != x) {
        st.push(pre[i]);
        i = pre[i];
    }

    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
}

int main() {
    int dp[1000001];
    int n;
    int cnt;

    queue<pair<int, int>> q;

    cin >> x;

    for (int i = 0; i <= 1000000; i++) {
        dp[i] = 0x7fffffff;
    }
    q.push({x, 0});

    while (!q.empty()) {
        n = q.front().first;
        cnt = q.front().second;

        q.pop();

        if (n == dest) {
            break;
        }

        if (n % 3 == 0 && dp[n / 3] > cnt + 1) {
            q.push({n / 3, cnt + 1});
            dp[n / 3] = cnt + 1;
            pre[n / 3] = n;
        }
        if (n % 2 == 0 && dp[n / 2] > cnt + 1) {
            q.push({n / 2, cnt + 1});
            dp[n / 2] = cnt + 1;
            pre[n / 2] = n;
        }
        if (dp[n - 1] > cnt + 1) {
            q.push({n - 1, cnt + 1});
            dp[n - 1] = cnt + 1;
            pre[n - 1] = n;
        }
    }

    cout << cnt << endl;
    find_route(dest);
    return 0;
}