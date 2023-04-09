#include <stdio.h>

int prime(int a)
{
    if (a == 1) return 0;
    if (a == 2) return 2;
    for (int i = 2; i < a; i++) {
        if (a % i == 0) return 0;
    }
    return a;
}

int main(void) {
    int M, N;
    int sum = 0;
    int min = 0;
    scanf("%d", &M);
    scanf("%d", &N);

    for (int i = M; i <= N; i++) {
       sum += prime(i);
       if (sum != 0 && min == 0) min = i;
    }
    if (sum == 0) printf("%d", -1);
    else {
        printf("%d\n", sum);
        printf("%d", min);
    }

}