#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char sentence[1000001];
    fgets(sentence, sizeof(sentence), stdin);
    int len = strlen(sentence);
    int word = 1;
    for (int i = 0 ; i < len ; i++) {
        if ((sentence[i] == ' ') && (i != 0) && (sentence[i-1] != ' ')) {
            word++;
        }
        if ((sentence[i] == ' ') && (i == len-2)) {
            word--;
        }
    }
    printf("%d", word);
}