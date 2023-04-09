#include <stdio.h>

int main(void) {
    int M, N;
    scanf("%d %d", &M, &N);
    char block[M][N+1];
    char B[9] = "BWBWBWBW";
    char W[9] = "WBWBWBWB";
    for (int i = 0 ; i < M ; i++) {
        scanf("%s", block[i]);
    }

    int r = N - 8 + 1;
    int d = M - 8 + 1;

    int count1[50][50] = {0, };
    int count2[50][50] = {0, };
    int min = 100;

    for (int l = 0 ; l < d ; l++) {
        for (int i = 0 ; i < r ; i++) {
            for (int k = 0 ; k < 8 ; k++) {
                for (int j = 0 ; j < 8 ; j++) {
                    if (k%2 == 0) {
                        if (block[k+l][i+j] != B[j]) {
                            count1[l][i]++;
                        }

                        if (block[k+l][i+j] != W[j]) {
                            count2[l][i]++;
                        }
                    } else {
                        if (block[k+l][i+j] != W[j]) {
                            count1[l][i]++;
                        }

                        if (block[k+l][i+j] != B[j]) {
                            count2[l][i]++;
                        }
                    }
                }
            }
            if (min > count1[l][i]) min = count1[l][i];
            if (min > count2[l][i]) min = count2[l][i];
        }
    }
    printf("%d", min);
}