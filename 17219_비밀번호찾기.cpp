#include <iostream>
#include <map>
#include <string>

using namespace std;

int N, M;
map<string, string> h;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string pass, url;
        cin >> url >> pass;

        h[url] = pass;
    }

    for (int i = 0; i < M; i++) {
        string url;
        cin >> url;

        cout << h[url] << '\n';
    }

    return 0;
}