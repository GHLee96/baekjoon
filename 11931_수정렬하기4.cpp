#include <algorithm>
#include <iostream>

using namespace std;

int N;
int arr[1000005];

bool cmp(int a, int b) { return a > b; }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + N, cmp);

    for (int i = 0; i < N; i++) {
        cout << arr[i] << '\n';
    }

    return 0;
}