#include <iostream>
#include <stack>

using namespace std;

int height[500005];
stack<pair<int, int>> s;
long long cnt;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> height[i];
    }

    for (int i = 1; i <= N; i++) {

        long long cnt_same = 1;

        while (!s.empty() && s.top().first < height[i]) {
            cnt += s.top().second;
            s.pop();
        }

        if (!s.empty()) {
            if (s.top().first == height[i]) {
                cnt += s.top().second;
                cnt_same += s.top().second;

                if (s.size() > 1) {
                    cnt++;
                }
                s.pop();
            } else {
                cnt++;
            }
        }

        s.push({height[i], cnt_same});
    }

    cout << cnt;

    return 0;
}