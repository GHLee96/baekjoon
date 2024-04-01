#include <iostream>

using namespace std;

int main() {
    int r, c;
    int max = -1;
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            int a;
            cin >> a;
            if (max < a) {
                r = i;
                c = j;
                max = a;
            }
        }
    }
    cout << max << endl << r << ' ' << c << endl;
    return 0;
}