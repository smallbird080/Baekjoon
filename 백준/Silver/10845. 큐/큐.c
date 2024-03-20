#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_SIZE 10001

typedef struct _Queue
{
    int size;
    int array[ARRAY_SIZE];
    int front,rear;
}Queue;

int isEmpty(Queue* Q){
    if (Q->size == 0)
        return 1;
    else
        return 0;
}

void push(Queue *Q){
    int newItem;
    scanf("%d", &newItem);
    Q->size++;
    Q->rear++;
    Q->array[(Q->rear)%ARRAY_SIZE] = newItem;
}

void pop(Queue* Q){
    if (isEmpty(Q)){
        printf("-1\n");
        return;
    }
    printf("%d\n",Q->array[(Q->front)%ARRAY_SIZE]);
    Q->front++;
    Q->size--;
}

void size(Queue* Q){
    printf("%d\n",Q->size);
    return;
}

void front(Queue* Q){
    if (isEmpty(Q)){
        printf("-1\n");
        return;
    }
    printf("%d\n",Q->array[(Q->front)%ARRAY_SIZE]);
}

void back(Queue* Q){
    if (isEmpty(Q)){
        printf("-1\n");
        return;
    }
    printf("%d\n",Q->array[(Q->rear)%ARRAY_SIZE]);
}

int main()
{
    Queue* Q = (Queue*)malloc(sizeof(Queue));
    Q->size = 0;
    Q->front = 0;
    Q->rear = -1;
    int tasks;
    char method[6];
    scanf("%d",&tasks);
    for (int i=0; i<tasks; i++){
        scanf("%s",method);
        if (!strcmp(method,"push")){
            push(Q);
        }
        else if (!strcmp(method,"pop")){
            pop(Q);
        }
        else if (!strcmp(method,"size")){
            size(Q);
        }
        else if (!strcmp(method,"empty")){
            printf("%d\n",isEmpty(Q));
        }
        else if (!strcmp(method,"front")){
            front(Q);
        }
        else if (!strcmp(method,"back")){
            back(Q);
        }
    }
}


