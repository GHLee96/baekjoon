#include <stdio.h>

int main(void) {
    int n;

    scanf("%d", &n);
    int num;
    double avg[1000];
    int count;

    for (int i = 0 ; i < n ; i++) {
        scanf("%d", &num);
        int sub[1000];
        int sum = 0;
        count = 0;
        for (int j = 0 ; j < num ; j++) {
            scanf("%d", &sub[j]);
            sum += sub[j];
        }
        avg[i] = (double)sum/num;
        for (int j = 0 ; j < num ; j++) {
            if (sub[j] > avg[i]) {
                count++;
            }
        }
        avg[i] = (double)count/num*100;
    }

    for (int i = 0 ; i < n ; i++) {
        printf("%.3f%%\n", avg[i]);
    }
}