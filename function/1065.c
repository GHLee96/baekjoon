#include <stdio.h>
int arith_seq(int n) {
    int result;
    int a, b, c = 0;

    a = n % 10;
    b = n/10 % 10;
    c = n/100 % 10;

    if (n == 1000) {
        return 0;
    } else {
        if (c == 0) {
            return 1;
        } else {
            if (c-b == b-a) {
                return 1;
            } else {
                return 0;
            }
        }    
    }
}

int main(void) {
    int N;
    int sum = 0;

    scanf("%d", &N);
    for (int i = 1 ; i <= N ; i++) {
        sum += arith_seq(i);
    }
    printf("%d", sum);
    
}