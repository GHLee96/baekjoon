#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int A[105][105];
int max_r;
int max_c;
int r, c, k;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> r >> c >> k;
    r--;
    c--;

    max_r = max_c = 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> A[i][j];
        }
    }

    if (A[r][c] == k) {
        cout << 0;
        return 0;
    } else {
        for (int i = 1; i <= 100; i++) {
            int tmp[105][105] = {0};

            if (max_r >= max_c) {
                // r 연산

                int tmp_max_c = max_c;
                for (int i = 0; i < max_r; i++) {
                    map<int, int> m;
                    for (int j = 0; j < max_c; j++) {
                        if (A[i][j] == 0)
                            continue;
                        m[A[i][j]]++;
                    }

                    vector<pair<int, int>> v(m.begin(), m.end());
                    sort(v.begin(), v.end(), cmp);
                    int j = 0;
                    for (auto x : v) {
                        tmp[i][j] = x.first;
                        tmp[i][j + 1] = x.second;
                        j += 2;

                        if (j == 100)
                            break;
                    }
                    tmp_max_c = max(tmp_max_c, j);
                }

                max_c = max(max_c, tmp_max_c);
                memcpy(A, tmp, sizeof(tmp));
            } else {
                // c 연산

                int tmp_max_r = max_r;
                for (int j = 0; j < max_c; j++) {
                    map<int, int> m;
                    for (int i = 0; i < max_r; i++) {
                        if (A[i][j] == 0)
                            continue;
                        m[A[i][j]]++;
                    }

                    vector<pair<int, int>> v(m.begin(), m.end());
                    sort(v.begin(), v.end(), cmp);
                    int i = 0;
                    for (auto x : v) {
                        tmp[i][j] = x.first;
                        tmp[i + 1][j] = x.second;
                        i += 2;

                        if (i == 100)
                            break;
                    }
                    tmp_max_r = max(tmp_max_r, i);
                }

                max_r = max(max_r, tmp_max_r);
                memcpy(A, tmp, sizeof(tmp));
            }

            if (A[r][c] == k) {
                cout << i;
                return 0;
            }
        }
    }

    cout << -1;

    return 0;
}