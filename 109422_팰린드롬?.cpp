#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int n;
vector<int> v;
vector<vector<int>> is_pal;
// int is_pal[2001][2001] = {
//     0,
// };

bool is_palindrome(int s, int e) {
    while (s < e) {
        if (v[s++] != v[e--]) return false;
    }
    return true;
}

int sol(int s, int e) {
    if (s == e) return 1;
    if (s + 1 == e) return v[s] == v[e];

    int &ret = is_pal[s][e];
    if (ret != -1) return ret;

    ret = sol(s + 1, e - 1) && v[s] == v[e];
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m;  // 질문 개수

    cin >> n;
    v.resize(n + 2);
    is_pal.resize(n + 1, vector<int>(n + 1, -1));

    for (int i = 1; i <= n; i++) cin >> v[i];

    // for (int i = 1; i <= n; i++) {
    //     is_pal[i][i] = 1;
    //     if (v[i] == v[i + 1]) is_pal[i][i + 1] = 1;
    // }

    // for (int i = 1; i <= n; i++) {
    //     int s = i - 1;
    //     int e = i + 1;

    //     while (s >= 1 && e <= n && s < e) {
    //         if (is_pal[s + 1][e - 1] && v[s] == v[e])
    //             is_pal[s--][e++] = 1;
    //         else
    //             break;
    //     }

    //     if (v[i] == v[i + 1]) {
    //         s = i - 1;
    //         e = i + 2;
    //     }
    //     while (s >= 1 && e <= n && s < e) {
    //         if (is_pal[s + 1][e - 1] && v[s] == v[e])
    //             is_pal[s--][e++] = 1;
    //         else
    //             break;
    //     }

    //     // for (int j = i; j <= n; j++) {
    //     //     if (is_pal[i + 1][j - 1] && v[i] == v[j]) is_pal[i][j] = 1;
    //     // }
    // }

    cin >> m;
    for (int i = 0; i < m; i++) {
        int s, e;
        cin >> s >> e;

        cout << sol(s, e) << "\n";
    }
    return 0;
}