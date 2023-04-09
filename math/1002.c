#include <stdio.h>
#include <math.h>

int main (void) {
    int x1, x2, y1, y2, r1, r2;
    int n = 0;
    scanf("%d", &n);
    for (int i = 0 ; i < n ; i++) {
        scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
        double d = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
        if (d == 0) {
            if (r1 == r2) {
                printf("%d\n", -1);
                continue;
            } else {
                printf("%d\n", 0);
                continue;
            }
        } else if (d == abs(r1 - r2)) {
            printf("%d\n", 1);
        } else if (d < abs(r1 - r2)) {
            printf("%d\n", 0);
        }
        else {
            if (d < r1 + r2) {
                printf("%d\n", 2);
                continue;
            } else if (d == r1 + r2) {
                printf("%d\n", 1);
                continue;
            } else {
                printf("%d\n", 0);
                continue;
            }
        }
    }
}