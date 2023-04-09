#include <stdio.h>
#include <string.h>

int main() {
    int n;
    int score = 0;
    char test[80];
    scanf("%d", &n);
    int result[n];
    
    for (int i = 0 ; i < n ; i++) {
        scanf("%s", test);
        score = 0;
        result[i] = 0;
        for (int j = 0 ; j < strlen(test) ; j++) {
            if (test[j] == 'O') {
                score++;
                result[i] += score;
            }
            if (test[j] == 'X') {
                score = 0;
            }
        }
    }
    for (int i = 0 ; i < n ; i++) {
        printf("%d\n", result[i]);
    }

    return 0;
}