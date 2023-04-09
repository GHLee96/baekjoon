#include <stdio.h>
void merge(int data[], int p, int q, int r, int n) {
    int i = p, j = q+1, k = p;
    int tmp[n]; // 새 배열
    while(i<=q && j<=r) {
        if(data[i] <= data[j]) tmp[k++] = data[i++];
        else tmp[k++] = data[j++];
    }
    while(i<=q) tmp[k++] = data[i++];
    while(j<=r) tmp[k++] = data[j++];
    for(int a = p; a<=r; a++) data[a] = tmp[a];
}

void mergeSort(int data[], int p, int r, int n) {
    int q;
    if(p<r) {
        q = (p+r)/2;
        mergeSort(data, p , q, n);
        mergeSort(data, q+1, r, n);
        merge(data, p, q, r, n);
    }
}


int main() {
    int n = 0;

    scanf("%d", &n);

    int num[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }

    mergeSort(num, 0, n-1, n);

    for (int i = 0; i < n; i++) {
        printf("%d", num[i]);
        if (i != n-1) {
            printf("\n");
        }
    }

    return 0;
}