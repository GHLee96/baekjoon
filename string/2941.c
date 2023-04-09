#include <stdio.h>
#include <string.h>

int main(void) {
    char input[101];
    scanf("%s", input);
    int len = strlen(input);
    int count = 0;

    for (int i = 0; i < len ; i++) {
        switch (input[i])
        {
        case '=':
            if (input[i-1] == 'z' && input[i-2] == 'd') count--;
            break;
        case 'j':
            if (input[i-1] == 'l' || input[i-1] == 'n') break;
            else count++; break;
        default:
            if(input[i] >= 'a' && input[i] <= 'z') count++;
            break;
        }
    }
    printf("%d", count);
}