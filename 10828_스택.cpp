#include <cstring>
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int st[100001] = {
        0,
    };
    int N;
    int i = -1;

    cin >> N;

    for (int input = 0; input < N; input++) {
        char cmd[6];
        int n;

        cin >> cmd;
        if (!strncmp(cmd, "push", 4)) {
            cin >> n;
            st[++i] = n;
            continue;
        } else if (!strncmp(cmd, "pop", 3)) {
            if (i == -1)
                cout << -1;
            else
                cout << st[i--];
        } else if (!strncmp(cmd, "size", 4)) {
            cout << i + 1;
        } else if (!strncmp(cmd, "empty", 5)) {
            if (i == -1)
                cout << 1;
            else
                cout << 0;
        } else {
            if (i == -1)
                cout << -1;
            else
                cout << st[i];
        }
        cout << '\n';
    }
    return 0;
}