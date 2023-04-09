#include <algorithm>
#include <iostream>

using namespace std;

int my_binary_search(int arr[], int size, int key) {
    int s = 0;
    int e = size - 1;
    int m;

    while (e >= s) {
        m = (s + e) / 2;
        if (arr[m] == key)
            return 1;
        else if (arr[m] > key)
            e = m - 1;
        else
            s = m + 1;
    }
    return 0;
}
int main() {
    int N, M;

    // ios::sync_with_stdio(0);
    // cin.tie(0);
    cin >> N;
    int A[N];
    for (int i = 0; i < N; i++) cin >> A[i];
    sort(A, A + N);

    cin >> M;
    int B;
    for (int i = 0; i < M; i++) {
        scanf("%d", &B);
        // cout << binary_search(A, A + N, B) << "\n";
        // cout << my_binary_search(A, N, B) << "\n";
        printf("%d\n", my_binary_search(A, N, B));
    }
    return 0;
}