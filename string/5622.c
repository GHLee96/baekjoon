#include <stdio.h>
#include <string.h>

int main(void) {
    char input[16];
    int time[] = {3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,8,9,9,9,10,10,10,10};
    scanf("%s", input);
    int len = strlen(input);
    int count = 0;
    for (int i = 0; i < len; i++)
    {
        count += time[input[i] - 'A'];
    }
    printf("%d", count);
}