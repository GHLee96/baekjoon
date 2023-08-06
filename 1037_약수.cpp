#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    int s;
    int e;

    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    cout << arr[0] * arr[N - 1];

    return 0;
}