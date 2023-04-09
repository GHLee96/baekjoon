#include <iostream>

using namespace std;

int main() {
    int V, A, B;

    cin >> A >> B >> V;

    int diff = A - B;
    int result = 1;

    if ((V - A) % diff == 0) {
        result += (V - A) / diff;
    } else {
        result += (V - A) / diff + 1;
    }
    cout << result;
    return 0;
}