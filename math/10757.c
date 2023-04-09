#include <stdio.h>
#include <string.h>

void (reverse(char *arr)) // pointer
/* https://intelligentcm.tistory.com/75
 */
{
    int len = strlen(arr);
    for (int i = 0 ; i < len/2 ; i++) {
        char t = arr[i];
        arr[i] = arr[len - i - 1];
        arr[len - i - 1] = t;
    }
}

int main(void) {
    char a[10002] = {0, };
    char b[10002] = {0, };
    char c[10003] = {0, };
    int len, carry = 0;
    scanf("%s %s", a, b);
    reverse(a);
    reverse(b);
    
    if (strlen(a) > strlen(b)) len = strlen(a);
    else len = strlen(b);
    for (int i = 0 ; i < len ; i++) {
        if (a[i] > '9' || a[i] < '0' && b[i] <= '9' && b[i] >= '0') a[i] = '0';
        else if (b[i] > '9' || b[i] < '0' && a[i] <= '9' && a[i] >= '0') b[i] = '0';
        

        if ((a[i] - '0') + (b[i] - '0') + carry >= 10) {
            c[i] = '0' + (a[i] - '0') + (b[i] - '0') + carry - 10;
            carry = 1;
        } else {
            c[i] = '0' + (a[i] - '0') + (b[i] - '0') + carry;
            carry = 0;
        }
    }
    if (carry == 1) {
        c[len] = '1';
    }
    reverse(c);
    printf("%s", c);
}