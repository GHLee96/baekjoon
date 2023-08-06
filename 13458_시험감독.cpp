#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    int B, C;

    cin >> N;
    vector<int> takers(N);
    for (int i = 0; i < N; i++) cin >> takers[i];
    cin >> B >> C;

    long long cnt = 0;
    for (int i = 0; i < N; i++) {
        if (takers[i] <= B) {
            cnt++;
        } else {
            int remain = takers[i] - B;
            cnt++;

            cnt += remain / C;
            if (remain % C != 0) cnt++;
        }
    }

    cout << cnt;
    return 0;
}