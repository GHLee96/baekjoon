#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, C;
vector<int> arr;
int main() {
    cin >> N >> C;

    arr.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int diff = arr[N - 1] - arr[0];

    int l = 0;
    int r = N - 1;

    while (1) {
    }

    return 0;
}