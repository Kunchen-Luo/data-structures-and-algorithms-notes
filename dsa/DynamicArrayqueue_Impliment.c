#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <stdio.h>
typedef struct {
    int *data;
    int size;
    int capacity;
    int extendRatio;
} DynamicArray;

DynamicArray* newDynamicArray() {
    DynamicArray *arr = (DynamicArray*)malloc(sizeof(DynamicArray));
    arr->size = 0;
    arr->capacity = 10;
    arr->extendRatio = 2;
    arr->data = (int*)malloc(sizeof(int) * arr->capacity);
    return arr;
}

void deDynamicArray(DynamicArray *arr) {
    free(arr->data);
    free(arr);
} 

void* extendDynamicArray(DynamicArray* arr) {
    int newcapacity = arr->extendRatio * arr->capacity;
    int* extendarr = (int*)malloc(newcapacity * sizeof(int));
    for(int i = 0; i < arr->size; i++) {
        extendarr[i] = arr->data[i];  //队列的头和尾由 front 和 queSize 决定，和数组的索引无关
    }                                 //拷贝前后 queue 的 front 和 queSize 不变，故队列的头尾不变
    arr->data = extendarr;                                    
    arr->capacity = newcapacity;
}
typedef struct {
    DynamicArray *arr;
    int front;
    int queSize;
    int quecapacity;
} DynamicArrayqueue;

DynamicArrayqueue *newDynamicArrayqueue() {
    DynamicArrayqueue *queue = (DynamicArrayqueue*)malloc(sizeof(DynamicArrayqueue));
    queue->arr = newDynamicArray();
    queue->front = 0;
    queue->queSize = queue->arr->size;
    queue->quecapacity = queue->arr->capacity;
    return queue;
}

void deDynamicArrayqueue(DynamicArrayqueue *queue) {
    free(queue->arr->data);
    free(queue->arr);
    free(queue);
}

int capacity(DynamicArrayqueue* queue) {
    return queue->quecapacity;
}
int size(DynamicArrayqueue* queue) {
    return queue->queSize;
}

bool isEmpty(DynamicArrayqueue* queue) {
    return queue->queSize == 0;
}

int peek(DynamicArrayqueue* queue) {
    assert(size(queue) != 0);
    return queue->arr->data[queue->front];
}

void push(DynamicArrayqueue* queue, int num) {
    if(queue->queSize == queue->quecapacity){
        extendDynamicArray(queue->arr);
        queue->quecapacity = queue->arr->capacity;
    }    
    int rear = (queue->front + queue->queSize) % queue->quecapacity;
    queue->arr->data[rear] = num;
    queue->queSize = ++(queue->arr->size);
}

int pop(DynamicArrayqueue* queue) {
    int num = peek(queue);
    queue->front = (queue->front + 1) % queue->quecapacity;
    queue->queSize = --(queue->arr->size);
    return num;
}

int *toArray(DynamicArrayqueue* queue) {
    int j = queue->front;
    int *res = (int*)calloc(queue->queSize, sizeof(int));
    for(int i = 0; i < queue->queSize; i++) {
        res[i] = queue->arr->data[j % queue->quecapacity];
        j++;
    }
    return res;
}

int main() {
    DynamicArrayqueue* queue = newDynamicArrayqueue();
    for(int i = 0; i < 100; i++) {
        push(queue, i);
    }
    int* arr = toArray(queue);
    for(int i = 0; i < 100; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("%d\n", size(queue));
    printf("%d\n", capacity(queue));
    for(int i = 0; i < 100; i++) {
        pop(queue);
    }
    printf("%d\n", size(queue));
    printf("%d\n", capacity(queue));
    return 0;
}

