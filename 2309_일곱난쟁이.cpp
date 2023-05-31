#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int T = 9;
    int sum = 0;
    int h[9];

    for (int i = 0; i < T; i++) {
        cin >> h[i];
        sum += h[i];
    }

    sort(h, h + T);

    for (int i = 0; i < T; i++) {
        for (int j = 0; j < T; j++) {
            if (sum - h[i] - h[j] == 100) {
                for (int k = 0; k < T; k++) {
                    if (k == i || k == j)
                        continue;
                    else
                        cout << h[k] << endl;
                }
                return 0;
            }
        }
    }

    return 0;
}