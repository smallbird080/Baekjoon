#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    struct Node* next;
    int data;
}Node;

typedef struct Queue{
    int size;
    Node* front;
    Node* rear;
}Queue;

void push(Queue* q, int data){
    Node* newItem = (Node*)malloc(sizeof(Node));
    newItem->data = data;
    newItem->next = NULL;
    q->rear->next = newItem;
    q->rear = newItem;
    q->size++;
    return;
}

void pop(Queue* q){
    if(q->front->next == NULL){
        printf("-1\n");
        return;
    }
    printf("%d\n",q->front->next->data);
    Node* tmp = q->front->next;
    q->front->next = tmp->next;
    free(tmp);
    q->size--;
    if (q->size==0)
        q->rear = q->front;
}

void front(Queue* q){
    if(q->front->next == NULL){
        printf("-1\n");
        return;
    }
    printf("%d\n",q->front->next->data);
}

void back(Queue* q){
    if(q->front->next == NULL){
        printf("-1\n");
        return;
    }
    printf("%d\n",q->rear->data);
}

void isEmpty(Queue* q){
    if (q->size == 0){
        printf("1\n");
        return;
    }
    printf("0\n");
    return;
}

void freeQ(Queue* q){
    Node* front = q->front;
    while (front != NULL){
        Node* temp = front->next;
        free(front);
        front = temp;
    }
}

int main(){
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = (Node*)malloc(sizeof(Node));
    queue->size = 0;
    queue->front->data = -1;
    queue->front->next = NULL;
    queue->rear = queue->front;
    int numTasks;
    int data;
    char method[6];
    scanf("%d",&numTasks);
    for (int i=0; i<numTasks; i++){
        scanf("%s",method);
        if (!strcmp(method,"push")){
            scanf("%d",&data);
            push(queue,data);
        }
        else if (!strcmp(method,"pop")){
            pop(queue);
        }
        else if (!strcmp(method,"size")){
            printf("%d\n",queue->size);
        }
        else if (!strcmp(method,"empty")){
            isEmpty(queue);
        }
        else if (!strcmp(method,"front")){
            front(queue);
        }
        else if (!strcmp(method,"back")){
            back(queue);
        }
    }
    freeQ(queue);
    free(queue);
}