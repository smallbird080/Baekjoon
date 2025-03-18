#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str[60];
    fgets(str,60,stdin);
    int len = strlen(str)-1;
    if (len <= 2 || str[0] != '\"' || str[len-1] != '\"'){
        printf("CE");
    }
    else{
        strncpy(str,str+1,len-2);
        str[len-2] = 0;
        printf("%s",str);
    }
}