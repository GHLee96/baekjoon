#include <stdio.h>

int main(void) {
    int n = 1;
    
    while (n != 0) {
        scanf("%d", &n);
        if (n == 0) break;
        int set[1000000] = {0,};
        set[1] = 1;
        for (int i = 2 ; i * i <= 2*n ; i++) {
            if (!set[i]) {
                for (int j = i * i ; j <= 2*n ; j += i) {
                    set[j] = 1; 
                }
            }
        }
        int count = 0;
        for (int i = n+1 ; i <= 2*n ; i++) {
            if (!set[i]) count++;
        }
        printf("%d\n", count);
    }
}