#include <stdio.h>

int main(void) {
    int a;
    int max = 0;
    int index = -1;
    for (int i = 0 ; i < 9 ; i++) {
        scanf("%d", &a);
        if (a > max) {
            max = a;
            index = i;
        } 
    }
    printf("%d\n", max);
    printf("%d\n", index+1);
}