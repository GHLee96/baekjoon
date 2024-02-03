#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int N = 20;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int P;
    cin >> P;

    for (int tc = 1; tc <= P; tc++) {
        vector<int> line;

        int tc_dummy;
        cin >> tc_dummy;

        int cnt = 0;
        for (int i = 0; i < N; i++) {
            int height;
            cin >> height;

            if (line.size() == 0) {
                line.push_back(height);
            } else {
                // 첫번째로 큰 학생 구하기
                auto first_upper =
                    upper_bound(line.begin(), line.end(), height);
                int idx = first_upper - line.begin();

                // 물러서는 횟수 더하기
                cnt += line.size() - idx;

                // 학생 삽입하기
                line.insert(line.begin() + idx, height);
            }
        }

        cout << tc << ' ' << cnt << '\n';
    }

    return 0;
}