#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Heap{
    int* arr;
    int maxSize;
    int size;
} Heap;


int extractMin(Heap* heap){
    if (!(heap->size))
        return 0;
    
    int min = heap->arr[1];
    heap->arr[1] = heap->arr[heap->size];
    heap->arr[heap->size] = INT_MAX;
    (heap->size)--;
    int idx = 1;
    while (1){
        int cIdx;
        int lIdx = idx*2;
        int rIdx = idx*2+1;
        if (lIdx > heap->size)
            break;
        else if (rIdx > heap->size)
            cIdx = lIdx;
        else
            cIdx = heap->arr[lIdx] < heap->arr[rIdx] ? lIdx : rIdx;
        if (heap->arr[idx] > heap->arr[cIdx]){
            int tmp = heap->arr[idx];
            heap->arr[idx] = heap->arr[cIdx];
            heap->arr[cIdx] = tmp;
            idx = cIdx;
        }
        else
            break;
    }

    return min;
}

void insert(Heap* heap, int num){
    heap->arr[++(heap->size)] = num;
    int idx = heap->size;
    int pIdx = idx/2;
    while (1){
        if (pIdx > 0 && heap->arr[pIdx] > heap->arr[idx]){
            int tmp = heap->arr[idx];
            heap->arr[idx] = heap->arr[pIdx];
            heap->arr[pIdx] = tmp;
            idx = pIdx;
            pIdx = idx/2;
        }
        else   
            break;
    }
}

int main(){
    int size;
    scanf("%d",&size);
    Heap* h = malloc(sizeof(Heap));
    h->arr = malloc((size+1)*sizeof(int));
    for (int i=0; i<=size; i++)
        h->arr[i] = INT_MAX;
    h->maxSize = size;
    h->size = 0;

    int input;
    while (size){
        scanf("%d",&input);
        if (!input){
            printf("%d\n",extractMin(h));
        }
        else {
            insert(h,input);
        }
        size--;
    }
}