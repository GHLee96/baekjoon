#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int arr[3];
    cin >> arr[0] >> arr[1] >> arr[2];
    sort(arr, arr + 3);
    for (int x : arr) {
        cout << x << " ";
    }
    return 0;
}