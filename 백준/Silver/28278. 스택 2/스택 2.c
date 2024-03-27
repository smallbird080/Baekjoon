#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    struct Node* next;
    int data;
    int size;
}Node;

void push(Node* stack, int data){
    Node* newItem = (Node*)malloc(sizeof(Node));
    newItem->data = data;
    Node* tmp = stack->next;
    stack->next = newItem;
    newItem->next = tmp;
    stack->size++;
    return;
}

void pop(Node* stack){
    if(stack->next==NULL){
        printf("-1\n");
        return;
    }
    printf("%d\n",stack->next->data);
    Node* tmp = stack->next;
    stack->next = tmp->next;
    free(tmp);
    stack->size--;
}

void top(Node* stack){
    if(stack->next==NULL){
        printf("-1\n");
        return;
    }
    printf("%d\n",stack->next->data);
}

void isEmpty(Node* stack){
    if (stack->size == 0){
        printf("1\n");
        return;
    }
    printf("0\n");
    return;
}

int main(){
    Node* stack = (Node*)malloc(sizeof(Node));
    stack->data = -1;
    stack->next = NULL;
    stack->size = 0;
    int numTasks;
    int task;
    int data;
    scanf("%d",&numTasks);
    for (int i=0; i<numTasks; i++){
        scanf("%d",&task);
        switch (task)
        {
        case 1:
            scanf("%d",&data);
            push(stack,data);
            break;
        case 2:
            pop(stack);
            break;
        case 3:
            printf("%d\n",stack->size);
            break;
        case 4:
            isEmpty(stack);
            break;
        case 5:
            top(stack);
            break;    
        default:
            break;
        }
    }
}