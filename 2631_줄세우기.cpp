#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    int children[N];
    for (int i = 0; i < N; i++) {
        cin >> children[i];
    }

    vector<int> LIS(N);
    int length = 0;

    for (int i = 0; i < N; i++) {
        int pos = lower_bound(LIS.begin(), LIS.begin() + length, children[i]) -
                  LIS.begin();

        if (pos == length) {
            LIS[length] = children[i];
            length++;
        } else {
            LIS[pos] = children[i];
        }
    }

    cout << N - length;

    return 0;
}
