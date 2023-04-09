#include <stdio.h>

int main(void) {
    long a, b, c;
    scanf("%ld %ld %ld", &a, &b, &c);
    long i = 0;
    if (b < c) {
        i = a/(c-b);
        printf("%ld", i+1);
    }
    else printf("%d", -1);
}