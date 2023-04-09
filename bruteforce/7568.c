#include <stdio.h>

int main(void) {
    int n;
    int a[50][2];
    scanf("%d", &n);
    for (int i = 0 ; i < n ; i++) {
        scanf("%d %d", &a[i][0], &a[i][1]);
    }

    int grade[n];
    for (int i = 0 ; i < n ; i++) {
        grade[i] = 1;
        for (int j = 0 ; j < n ; j++) {
            if (j == i) continue;
            if (a[i][0] < a[j][0] && a[i][1] < a[j][1]) {
                grade[i]++;
            }
        }
        printf("%d ", grade[i]);
    }
}