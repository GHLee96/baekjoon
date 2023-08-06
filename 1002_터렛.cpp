#include <cmath>
#include <iostream>

using namespace std;

struct coord {
    int x, y;
};

struct info {
    struct coord coord;
    int r;
};

int main() {
    info a, b;
    int T;

    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> a.coord.x >> a.coord.y >> a.r;
        cin >> b.coord.x >> b.coord.y >> b.r;

        int dis =
            pow((b.coord.x - a.coord.x), 2) + pow((b.coord.y - a.coord.y), 2);

        int sum_r = pow(a.r + b.r, 2);
        int diff_r = pow(a.r - b.r, 2);
        int res;

        if (dis == 0) {
            if (a.r == b.r)
                res = -1;
            else
                res = 0;
        } else {
            if (dis > sum_r || dis < diff_r) {
                res = 0;
            } else if (dis == sum_r || dis == diff_r) {
                res = 1;
            } else {
                res = 2;
            }
        }

        cout << res << "\n";
    }

    return 0;
}
