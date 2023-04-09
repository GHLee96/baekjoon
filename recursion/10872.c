#include <stdio.h>
int factorial(int a)
{
    if (a == 1 || a == 0) return 1;
    return a * factorial(a-1);
}

int main(void) {
    int N;
    scanf("%d", &N);    
    printf("%d", factorial(N));
}