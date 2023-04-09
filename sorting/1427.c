#include <stdio.h>
#include <string.h>

int main() {

    char arr[11];
    int n;

    fgets(arr, 11, stdin);
    int len = strlen(arr);

    for (int i = 0; i < len - 1; i++) {
        for (int j = i; j < len; j++) {
            if (arr[i] < arr[j]) {
                n = arr[i];
                arr[i] = arr[j];
                arr[j] = n;
            }
        }
    }

    fputs(arr, stdout);

    return 0;
}