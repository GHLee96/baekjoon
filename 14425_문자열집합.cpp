#include <iostream>
#include <map>
#include <string>

using namespace std;

map<string, int> m;
int N, M;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;

        m[str]++;
    }

    int res = 0;
    for (int i = 0; i < M; i++) {
        string str;
        cin >> str;

        if (m[str])
            res++;
    }

    cout << res << endl;

    return 0;
}