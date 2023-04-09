#include <stdio.h>

int main(void) {
    int x, y, w, h;
    scanf("%d %d %d %d", &x, &y, &w, &h);

    int x_d, y_d;
    if (x < w-x) x_d = x;
    else x_d = w-x;

    if (y < h-y) y_d = y;
    else y_d = h-y;

    if (x_d < y_d) printf("%d", x_d);
    else printf("%d", y_d);

}