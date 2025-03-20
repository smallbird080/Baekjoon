#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX(x,y) ((x) > (y) ? (x) : (y))

void printLCS(char *x, int **b, int i, int j){
    if (i == 0 || j == 0)
        return;
    if (b[i][j] == 0){
        printLCS(x, b, i - 1, j - 1);
        printf("%c", x[i - 1]);
    }
    else if (b[i][j] == 1)
        printLCS(x, b, i - 1, j);
    else
        printLCS(x, b, i, j - 1);
}


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
    int** track = calloc(xLen+1,sizeof(int*));
    for (int i=0; i<=xLen; i++){
        dp[i] = calloc(yLen+1,sizeof(int));
        track[i] = calloc(yLen+1,sizeof(int));
    }
    for (int i=1; i<=xLen; i++){
        for (int j=1; j<=yLen; j++){
            if (x[i - 1] == y[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
                track[i][j] = 0;
            }
            else if (dp[i - 1][j] >= dp[i][j - 1]){
                dp[i][j] = dp[i - 1][j];
                track[i][j] = 1;
            }
            else{
                dp[i][j] = dp[i][j - 1];
                track[i][j] = 2;
            }
        }
    }

    int len = dp[xLen][yLen];
    printf("%d\n",len);
    if (len)
        printLCS(x,track,xLen,yLen);

    for (int i=0; i<=xLen; i++){
        free(dp[i]);
        free(track[i]);
    }
    free(track);
    free(dp);
}