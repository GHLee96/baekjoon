#include <stdio.h>
int selfnum(int n) {
    int sum = n;

    while(n>0) {
        sum += n%10;
        n/=10;
    }
    return sum;
}

int main(void) {
    int arr[100001], check;

    for (int i = 1 ; i <= 10000 ; i++) {
        check = selfnum(i);
        if (check <= 10000) {
            arr[check] = 1;
        }
    }
    for (int i = 1 ; i <= 10000 ; i++) {
        if (arr[i] != 1) {
            printf("%d\n", i);
        }
    }
}
