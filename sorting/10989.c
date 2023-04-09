#include <stdio.h>

int main() {

    int N;
    int max = 0;

    scanf("%d", &N);
    int arr[N];
    int result[N];

    for (int i = 0; i < N; i++) {
        result[i] = 0;
    }

    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < N; i++) {
        if (arr[i] > max) {
            max = arr[i] + 1;
        }
    }

    int count[max];

    for (int i = 0; i < max; i++) {
        count[i] = 0;
    }
    
    for (int i = 0; i < N; i++) {
        count[arr[i]]++;
    }

    for (int i = 1; i < max; i++) {
        count[i] += count[i - 1];
    }

    for (int i = N - 1; i >= 0; i--) {
        int value = arr[i];
        count[value]--;
        result[count[value]] = value;
    }

    for (int i = 0; i < N; i++) {
        printf("%d\n", result[i]);
    }

    return 0;
}