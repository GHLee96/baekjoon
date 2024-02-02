#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        int N;
        cin >> N;

        map<string, int> h;
        vector<string> arr;
        for (int i = 0; i < N; i++) {
            string name, subject;
            cin >> name >> subject;

            if (!h[subject])
                arr.push_back(subject);
            h[subject]++;
        }

        int res = 1;
        for (auto x : arr) {
            res *= h[x] + 1;
        }

        cout << res - 1 << '\n';
    }

    return 0;
}