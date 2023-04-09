#include <stdio.h>

int main(void) {
    double r = 0;
    double pi = 3.14159265359;
    scanf("%lf", &r);
    
    printf("%.6lf\n", r*r*pi);
    printf("%.6lf", r*r*2);
}