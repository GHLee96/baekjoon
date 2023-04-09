#include <stdio.h>

int main(void) {
    int r = 0;
    float pi = 3.14159265359;
    scanf("%d", &r);
    
    printf("%.6f\n", r*r*pi);
    printf("%.6f", (float) r*r*2);
}