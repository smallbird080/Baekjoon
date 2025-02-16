#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(x,y) ((x) > (y) ? (x) : (y))

int main(){
    char x[1010];
    char y[1010];
    fgets(x, 1010, stdin);
    fgets(y, 1010, stdin);

    x[strcspn(x, "\n")] = '\0';
    y[strcspn(y, "\n")] = '\0';
    int xLen = strlen(x);
    int yLen = strlen(y);
    int** dp = calloc(xLen+1,sizeof(int*));
    for (int i=0; i<=xLen; i++){
        dp[i] = calloc(yLen+1,sizeof(int));
    }
    for (int i=1; i<=xLen; i++){
        for (int j=1; j<=yLen; j++){
            if (x[i-1] == y[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else
                dp[i][j] = MAX(dp[i-1][j],dp[i][j-1]);
        }
    }

    printf("%d",dp[xLen][yLen]);

    for (int i=0; i<=xLen; i++)
        free(dp[i]);
    free(dp);
}