#include <stdio.h>

int main(void) {
    int n, m;
    int a[100];
    int max = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0 ; i < n ; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0 ; i < n-2 ; i++) {
        for (int j = i+1 ; j < n-1 ; j++) {
            for (int k = j+1 ; k < n ; k++) {
                if (max < a[i] + a[j] + a[k] && a[i] + a[j] + a[k] <= m) {
                    max = a[i] + a[j] + a[k];
                }
            }
        }
    }
    printf("%d", max);
}