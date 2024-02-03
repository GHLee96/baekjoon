#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

map<string, int> arr;
int N;
int M;

vector<string> ans;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        arr[str]++;
    }

    for (int i = 0; i < M; i++) {
        string str;
        cin >> str;
        if (arr[str]) {
            ans.push_back(str);
        }
    }

    sort(ans.begin(), ans.end());

    cout << ans.size() << '\n';
    for (auto x : ans) {
        cout << x << '\n';
    }
    return 0;
}