#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char num[6];
    while (1){
        scanf("%5s",num);
        if (num[0] == '0')
            return 0;
        int len = strlen(num);
        char palin = 1;
        for (int i=0; i<len/2; i++){
            if (num[i] != num[len-1-i]){
                palin = 0;
                break;
            }
        }
        if (palin){
            printf("yes\n");
        }
        else{
            printf("no\n");
        }
    }
}