#include <stdio.h>

int main() {
    int num, a, b, c = 0;
    int i = 0;

    scanf("%d", &num);
    c = num;

    do {
        a = c/10;
        b = c%10;
        c = b*10 + (a+b)%10;
        i++;
    } while (c != num);
    
    printf("%d", i);

    return 0;
}