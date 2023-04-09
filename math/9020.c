#include <stdio.h>

int main(void) {
    int n = 1;
    int num = 0;
    scanf("%d", &num);
    int set[10001] = {0, };
    set[1] = 1;
    for (int i = 2 ; i * i <= 10000 ; i++) {
        if (!set[i]) {
            for (int j = i * i ; j <= 10000 ; j += i) {
                set[j] = 1; 
            }
        }
    }
    
    for (int k = 0 ; k < num ; k++)  {
        scanf("%d", &n);
        for (int i = n/2 ; i < n ; i++) {
            if (!set[i] && !set[n - i]) {
                printf("%d %d\n", n - i, i);
                break;
            }
        }
    }
}