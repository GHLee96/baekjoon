#include <stdio.h>
#include <math.h>
void hanoi(int s, int t, int d, int n)
{
    if (n == 1) printf("%d %d\n", s, d);
    else {
        hanoi(s, d, t, n-1);
        printf("%d %d\n", s, d);
        hanoi(t, s, d, n-1);
    }
}

int main(void) {
    int n;
    scanf("%d", &n);
    printf("%d\n", (int) pow(2, n) - 1);
    hanoi(1, 2, 3, n);
}