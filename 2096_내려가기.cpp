#include <cstring>
#include <iostream>

using namespace std;

int main() {
    int n;
    const int n_col = 3;
    int score_max[3] = {
        0,
    };
    int score_min[3] = {
        0,
    };
    int pre_max[3] = {
        0,
    };
    int pre_min[3] = {
        0,
    };

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n_col; j++) {
            int score;
            cin >> score;
            score_max[j] = score_min[j] = score;
            score_max[j] += max(
                pre_max[1], j == 1 ? max(pre_max[0], pre_max[2]) : pre_max[j]);
            score_min[j] += min(
                pre_min[1], j == 1 ? min(pre_min[0], pre_min[2]) : pre_min[j]);
        }

        memcpy(pre_max, score_max, sizeof(score_max));
        memcpy(pre_min, score_min, sizeof(score_min));
    }

    int res_max = 0;
    int res_min = 0x7fffffff;
    for (auto score : score_max) {
        res_max = max(res_max, score);
    }
    for (auto score : score_min) {
        res_min = min(res_min, score);
    }

    cout << res_max << " " << res_min;

    return 0;
}