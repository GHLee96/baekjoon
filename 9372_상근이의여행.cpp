#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;

    cin >> T;
    for (int i = 1; i <= T; i++) {
        int N, M;
        cin >> N >> M;

        for (int j = 0; j < M; j++) {
            int a, b;
            cin >> a >> b;
        }
        cout << N - 1 << '\n';
    }
    return 0;
}