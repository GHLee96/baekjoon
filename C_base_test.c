#include <stdio.h>

void change_value(int *A, int *B)
{
    int C = *A;
    *A = *B;
     *B = C;
} 

int main(void) {
    int A = 3;
    int B = 2;

    int *C;
    printf("%d\n", *C);
    change_value(&A, &B);



    printf("%lu", sizeof(char));
}