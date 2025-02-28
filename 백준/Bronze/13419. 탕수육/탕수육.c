#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char word[60];
    int t;
    scanf("%d",&t);
    while (t--){
        scanf("%29s",word);
        int len = strlen(word);
        if (len & 1){
            strncat(word+len,word,len);
            len *= 2;
        }
        for (int i=0; i<len/2; i++)
            printf("%c",word[i*2]);
        printf("\n");
        for (int i=0; i<len/2; i++)
            printf("%c",word[i*2+1]);
        printf("\n");
    }
}
