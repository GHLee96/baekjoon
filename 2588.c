#include "stdio.h"

int main() {
    int a, b;
    int o, t, h;
    
    scanf("%d %d", &a, &b);

    h = b/100;
    t = (b%100)/10;
    o = (b%100)%10;
 
    printf("%d\n", a*o);
    printf("%d\n", a*t);
    printf("%d\n", a*h);
    printf("%d\n", a*b);

    return 0;
}