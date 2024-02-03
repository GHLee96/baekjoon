#include <iostream>

using namespace std;

int main() {
    long long N;
    cin >> N;

    int count = 0;

    while (N > 1) {
        if (N % 3 == 0) {
            N /= 3;
        } else if (N % 2 == 0) {
            N /= 2;
        } else {
            N -= 1;
        }
        count++;
    }

    cout << count << endl;

    return 0;
}