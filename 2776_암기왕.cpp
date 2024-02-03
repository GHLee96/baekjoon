#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<int, int> m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T, N, M;

    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        cin >> N;

        for (int i = 0; i < N; i++) {
            int a;
            cin >> a;

            m[a] = 1;
        }

        cin >> M;

        for (int j = 0; j < M; j++) {
            int b;
            cin >> b;

            cout << m[b] << '\n';
        }

        m.clear();
    }

    return 0;
}