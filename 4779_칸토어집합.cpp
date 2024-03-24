#include <cstring>
#include <iostream>
#include <math.h>

using namespace std;

// int N;

// char arr[540000];

// void sol(int s, int e) {
//     if (s == e) {
//         arr[s] = '-';
//         return;
//     }

//     sol(s, (e - s + 1) / 3 + s - 1);
//     sol((e - s + 1) / 3 * 2 + s, e);
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     while (cin >> N) {
//         int len = pow(3, N);

//         sol(1, len);
//         for (int i = 1; i <= len; i++) {
//             if (arr[i] == '\0')
//                 cout << ' ';
//             else
//                 cout << arr[i];
//         }
//         cout << '\n';
//         memset(arr, 0, sizeof(arr));
//     }

//     return 0;
// }

void sol(int n) {
    if (n == 0) {
        cout << '-';
        return;
    }

    sol(n - 1);
    int len = pow(3, n - 1);
    for (int i = 0; i < len; i++)
        cout << ' ';
    sol(n - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    while (cin >> n) {
        sol(n);
        cout << '\n';
    }
}