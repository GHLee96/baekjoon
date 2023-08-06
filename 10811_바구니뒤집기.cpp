#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) arr[i] = i;

    while (m-- > 0) {
        int s, e;
        cin >> s >> e;

        reverse(arr.begin() + s, arr.begin() + e + 1);
    }

    for (int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

/*
    1 2 3 4 5
    2 1 3 4 5
    2 1 4 3 5
    3 4 1 2 5
*/