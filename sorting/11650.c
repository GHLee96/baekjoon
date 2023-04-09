#include <stdio.h>

int main() {
    int n, a[100001], b[100001], tmp;

    scanf("%d", &n);
    char arr[3];

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a[i], &b[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i] > a[i + 1]) {
                tmp = a[i + 1];
                a[i + 1] = a[i]; 
                a[i] = tmp;
            } else if (a[i] == a[i + 1]) {
                if (b[i] > b[i + 1]) {
                    tmp = b[i + 1];
                    b[i + 1] = b[i]; 
                    b[i] = tmp;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d %d\n", a[i], b[i]);
    }

    return 0;
}