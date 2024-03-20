#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Stack
{
    int size;
    int array[10001];
    int TOS;
}Stack;

int isEmpty(Stack* S){
    if (S->TOS == -1)
        return 1;
    else
        return 0;
}

void push(Stack *S){
    int newItem;
    scanf("%d", &newItem);
    S->TOS++;
    S->size++;
    S->array[S->TOS] = newItem;
}

void pop(Stack* S){
    if (isEmpty(S)){
        printf("-1\n");
        return;
    }
    printf("%d\n",S->array[S->TOS]);
    S->TOS--;
    S->size--;
}

void size(Stack* S){
    printf("%d\n",S->size);
    return;
}

void top(Stack* S){
    if (isEmpty(S)){
        printf("-1\n");
        return;
    }
    printf("%d\n",S->array[S->TOS]);
}

int main()
{
    Stack* S = (Stack*)malloc(sizeof(Stack));
    S->size = 0;
    S->TOS = -1;
    int tasks;
    char method[6];
    scanf("%d",&tasks);
    for (int i=0; i<tasks; i++){
        scanf("%s",method);
        if (!strcmp(method,"push")){
            push(S);
        }
        else if (!strcmp(method,"pop")){
            pop(S);
        }
        else if (!strcmp(method,"size")){
            size(S);
        }
        else if (!strcmp(method,"empty")){
            printf("%d\n",isEmpty(S));
        }
        else if (!strcmp(method,"top")){
            top(S);
        }
    }
}


