#include <iostream>

using namespace std;

int main() {
    int cost;
    cin >> cost;

    int change[] = {500, 100, 50, 10, 5, 1};

    int rest = 1000 - cost;
    int cnt = 0;

    for (auto c : change) {
        cnt += rest / c;
        rest %= c;
    }

    cout << cnt;
    return 0;
}