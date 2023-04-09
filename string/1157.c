#include <stdio.h>
#include <string.h>

int main() {
    char word[1000001];
    int alpha[26] = {0, };
    int max_num = 0;
    int max_word = -1;
    int dup = 0;

    scanf("%s", word);
    int len = strlen(word);

    for (int i = 0 ; i < len ; i++) {
        for (int j = 0 ; j < 'z'-'a'+1 ; j++) {
            if (word[i] == 'a'+j) {
                alpha[j]++;
            }
            if (word[i] == 'A'+j) {
                alpha[j]++;
            }
        }
    }

    for (int i = 0 ; i < 'z'-'a'+1 ; i++) {
        if (alpha[i] == max_num) {
            dup++;
        }
        if (alpha[i] > max_num) {
            max_num = alpha[i];
            max_word = i;
            dup = 0;
        }
    }

    if (dup == 0) {
        printf("%c", 'A'+max_word);
    } else {
        printf("?");
    }
    return 0;
}