#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        long m = 0;
        int result = 0;
        while (1) {
            if ((y-x) >= (m*(m+1)/2 + m*(m-1)/2) && (y-x) < ((m+1)*(m+2)/2 + m*(m+1)/2)) break;
            m++;
        }
        result = (m+m-1);
        if ((y-x) > (m*m)) {
            if ((y-x-m*m) > m) result += 2;
            else result += 1;            
        }
        printf("%d\n", result);
    }
}