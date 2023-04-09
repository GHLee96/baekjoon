#include <stdio.h>

int main() {
    int n, max = 0;
    scanf("%d", &n);
    int subject[n];
    int sum = 0;
    for (int i = 0 ; i < n ; i++) {
        scanf("%d", &subject[i]);

        if (max < subject[i]) {
            max = subject[i];
        }
    }

    for (int i = 0 ; i < n ; i++) {
        sum += subject[i];
    }
    float result = (float)sum/max*100/n;

    printf("%0.2f", result);

    return 0;
}