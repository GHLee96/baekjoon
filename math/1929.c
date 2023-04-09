#include <stdio.h>

int main(void) {
    int M, N;
    long long a;
    int set[1000001] = {0,};
    scanf("%d %d", &M, &N);

    set[1] = 1;
    for (long long i = 2 ; i * i <= N ; i++) {
        if (!set[i]) {
            for (long long j = i * i ; j <= N ; j += i) {
                set[j] = 1; 
            }
        }
        a = i;
    }
    for (int i = M ; i <= N ; i++) {
        if (!set[i]) printf("%d\n", i);
    }
}