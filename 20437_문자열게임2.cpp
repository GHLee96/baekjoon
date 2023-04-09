#include <cstring>
#include <iostream>

using namespace std;
string W;
int T, K;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test_case;

    cin >> T;
    for (test_case = 1; test_case <= T; test_case++) {
        cin >> W;
        cin >> K;

        int size = W.length();
        int min_window = 0x7fffffff;
        int max_window = 0;
        int cnt[27] = {
            0,
        };
        int first_i[27];
        memset(first_i, -1, sizeof(first_i));

        int all_max = 0;
        for (int i = 0; i < size; i++) {
            if (++cnt[W[i] - 'a'] == K) {
                if (first_i[W[i] - 'a'] == -1) {
                    first_i[W[i] - 'a'] = W.find(W[i]);
                    min_window = min(min_window, i - first_i[W[i] - 'a'] + 1);
                    max_window = max(max_window, i - first_i[W[i] - 'a'] + 1);
                } else {
                    first_i[W[i] - 'a'] = W.find(W[i], first_i[W[i] - 'a'] + 1);
                    min_window = min(min_window, i - first_i[W[i] - 'a'] + 1);
                    max_window = max(max_window, i - first_i[W[i] - 'a'] + 1);
                }

                cnt[W[i] - 'a']--;
            }
        }

        if (max_window == 0)
            cout << "-1\n";
        else
            cout << min_window << " " << max_window << "\n";
    }
    return 0;
}