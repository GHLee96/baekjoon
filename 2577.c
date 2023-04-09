#include <stdio.h>

int main(){
    int a, b, c, d, num;
    int arr[10] = {0, };
    scanf("%d %d %d", &a, &b, &c);
    d = a*b*c;

    while (d > 0) {
        num = d % 10;
        arr[num]++;
        d /= 10;
    }

    for (int i =0 ; i < 10 ; i++) {
        printf("%d\n", arr[i]);
    }

    return 0;
}