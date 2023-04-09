#include <stdio.h>

void bubble_sort(int arr[], int size)   
{
    int temp;

    for (int i = 0; i < size; i++)   
    {
        for (int j = 0; j < size - i - 1; j++)  
        {
            if (arr[j] > arr[j + 1])          
            {                                
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;           
            }
        }
    }
}
int main() {
    int n = 0;

    scanf("%d", &n);

    int num[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }

    bubble_sort(num, sizeof(num) / sizeof(int));

    for (int i = 0; i < n; i++) {
        printf("%d", num[i]);
        if (i != n-1) {
            printf("\n");
        }
    }

    return 0;
}