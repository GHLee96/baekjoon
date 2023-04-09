#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
    char str[8];
    char *str1[2] = {NULL, };
    int i = 0;
    fgets(str, sizeof(str), stdin);

    char *ptr = strtok(str, " ");

    while (ptr != NULL) {
        str1[i] = ptr;
        i++;
        ptr = strtok(NULL, " ");
    }

    char *end;
    int num1 = strtof(str1[0], &end);
    int num2 = strtof(str1[1], &end);

    num1 = num1%10*100 + num1%100/10*10 +num1/100;
    num2 = num2%10*100 + num2%100/10*10 +num2/100;

    if (num1 > num2) {
        printf("%d", num1);
    } else {
        printf("%d", num2);
    }

}