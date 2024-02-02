#include <algorithm>
#include <iostream>

using namespace std;

int A[55];
int B[55];
int N;

bool cmp(int a, int b) { return a > b; };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }

    sort(A, A + N);
    sort(B, B + N, cmp);

    int res = 0;
    for (int i = 0; i < N; i++) {
        res += A[i] * B[i];
    }

    cout << res << endl;

    return 0;
}