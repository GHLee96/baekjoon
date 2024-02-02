#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<string, int> m;

int main() {
    int N;
    cin >> N;

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        string cmd;
        cin >> cmd;

        if (cmd == "ENTER") {
            m.clear();
        } else {
            if (!m[cmd]) {
                cnt++;
                m[cmd] = 1;
            }
        }
    }

    cout << cnt << endl;

    return 0;
}