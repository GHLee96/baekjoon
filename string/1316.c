#include <stdio.h>
#include <string.h>

int main(void) {
    int num;
    char word[101];
    int count = 0;

    scanf("%d", &num);
    for (int i = 0 ; i < num ; i++) {
        scanf("%s", word);
        int alphabet[26] = {0, };
        int len = strlen(word);
        int check = 1;

        for (int j = 0 ; j < len ; j++) {
            int index = word[j] - 'a';
            if (word[j] != word[j-1] && alphabet[index] != 0) {
                check = 0;
                break;
            }
            alphabet[index]++;
        }
        if (check == 1) count++;
    }
    printf("%d", count);
}