/* #include <iostream>

using namespace std;

int main() {
    long long X, Y, W, S;
    cin >> X >> Y >> W >> S;

    long long time = min(X, Y) * S;

    long long time1 = abs(Y - X) * W;

    long long time2 = min(X, Y) * S;
    if (abs(X - Y) % 2)
        time2 += (abs(X - Y) - 1) * S + W;
    else
        time2 += abs(X - Y) * S;

    long long time3 = (X + Y) * W;

    time = min(time1, time2);
    time = min(time, time3);
    cout << time;

    return 0;
}
 */

#include <iostream>
using namespace std;

int main() {
    long long X, Y, W, S;
    cin >> X >> Y >> W >> S;

    long long time1 = (X + Y) * W;
    long long time2 = min(X, Y) * S;

    time2 += min(abs(X - Y) * W, (abs(X - Y) % 2 == 1 ? (abs(X - Y) - 1) * S + W
                                                      : abs(X - Y) * S));

    cout << min(time1, time2);
    return 0;
}