#include <algorithm>
#include <iostream>

using namespace std;

int N = 5;
int arr[5];
int main() {
    int sum = 0;
    for (int i = 0; i < N; i++) {
        int score;
        cin >> score;
        arr[i] = score;
        sum += score;
    }
    sort(arr, arr + N);

    cout << sum / N << endl << arr[2] << endl;
    return 0;
}