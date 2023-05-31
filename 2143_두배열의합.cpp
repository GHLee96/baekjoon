#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> a;
vector<int> b;

bool cmp(long long a, long long b) { return b < a; }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T, len_a, len_b;
    cin >> T;
    cin >> len_a;
    a.resize(len_a);

    for (int i = 0; i < len_a; i++) {
        cin >> a[i];
    }

    cin >> len_b;
    b.resize(len_b);
    for (int i = 0; i < len_b; i++) {
        cin >> b[i];
    }

    for (int i = 0; i < len_a; i++) {
        long long sum = a[i];
        for (int j = i + 1; j < len_a; j++) {
            sum += a[j];
            a.push_back(sum);
        }
    }

    for (int i = 0; i < len_b; i++) {
        long long sum = b[i];
        for (int j = i + 1; j < len_b; j++) {
            sum += b[j];
            b.push_back(sum);
        }
    }

    sort(b.begin(), b.end());

    long long cnt = 0;
    for (int i = 0; i < a.size(); i++) {
        cnt += upper_bound(b.begin(), b.end(), T - a[i]) -
               lower_bound(b.begin(), b.end(), T - a[i]);
    }

    cout << cnt;

    return 0;
}