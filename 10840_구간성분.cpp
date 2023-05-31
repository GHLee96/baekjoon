#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string str1, str2;
    set<vector<int> > set;
    int res = 0;

    cin >> str1 >> str2;

    int len_str1 = str1.length();
    int len_str2 = str2.length();

    for (int i = 0; i < len_str1; i++) {
        vector<int> v(26);

        for (int j = i; j < len_str1; j++) {
            v[str1[j] - 'a']++;

            set.insert(v);
        }
    }

    for (int i = 0; i < len_str2; i++) {
        vector<int> v(26);

        for (int j = i; j < len_str2; j++) {
            v[str2[j] - 'a']++;

            if (set.count(v)) res = max(res, j - i + 1);
        }
    }

    cout << res;
}
