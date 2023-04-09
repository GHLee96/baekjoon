#include <stdio.h>

int main() {
    int n, a;
    int max, min = -1;

    scanf("%d", &n);

    for (int i = 0 ; i < n ; i++) {
        scanf("%d", &a);
        if (i == 0) {
            max = a;
            min = a;
        }
        if (max < a) {
            max = a;
        }
        if (min > a) {
            min = a;
        }
    }
    printf("%d %d", min, max);
    return 0;
}