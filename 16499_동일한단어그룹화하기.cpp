#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;

    set<map<int, int>> s;

    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;

        map<int, int> cnt;
        for (auto x : str) {
            cnt[x]++;
        }

        s.insert(cnt);
    }

    cout << s.size() << endl;
    return 0;
}