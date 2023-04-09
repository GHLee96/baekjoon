#include <stdio.h>

int main(void) {
    long i = 0;
    long N;
    scanf("%ld", &N);
    while (N > 1 + 3*i*(i-1)) i++;
    if (N == 1) i = 1;
    printf("%ld", i);
}