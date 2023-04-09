#include <stdio.h>

int main(void) {
    int A, B, V;
    int h = 0;
    scanf("%d %d %d", &A, &B, &V);
    h = (V-A) / (A-B) + 1;
    if ((V-A) % (A-B) != 0) h++;
    printf("%d", h);
}