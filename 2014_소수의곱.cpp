#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int K, N;
vector<long long> p;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
    q;

void sol() {
    long long c;
    int cnt = 1;
    int pre;
    while (cnt++ < N) {
        c = q.top().first;
        pre = q.top().second;
        q.pop();

        for (auto x : p) {
            if (c * x > 0x7fffffff || pre < x) break;
            q.push({c * x, x});
        }
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> K >> N;

    p.resize(K);
    for (int i = 0; i < K; i++) {
        cin >> p[i];
        q.push({p[i], p[i]});
    }

    sol();
    cout << q.top().first;

    return 0;
}