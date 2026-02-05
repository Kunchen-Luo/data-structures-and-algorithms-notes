#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <assert.h>
typedef struct {
    int *data;
    int size;
    int capacity;
    int extendRatio;
} DynamicArray;

DynamicArray* newDynamicArray(int capacity) {
    DynamicArray *arr = (DynamicArray*)malloc(sizeof(DynamicArray));
    arr->size = 0;
    arr->capacity = capacity;
    arr->extendRatio = 2;
    arr->data = (int*)malloc(sizeof(int) * arr->capacity);
    return arr;
}

void deDynamicArray(DynamicArray* arr) {
    free(arr->data);;
    free(arr);
}

typedef struct {
    DynamicArray *nums;
    int front;
    int queSize;
    int queCapacity;
} DynamicArrayDequeue;

DynamicArrayDequeue *newDynamicArrayDequeue(int capacity) {
    DynamicArrayDequeue *deque = (DynamicArrayDequeue*)malloc(sizeof(DynamicArrayDequeue));
    deque->queCapacity = capacity;
    deque->nums = newDynamicArray(deque->queCapacity);
    deque->front = deque->queSize = 0;
    return deque;
}

void deDynamicArrayDequeue(DynamicArrayDequeue *deque) {
    free(deque->nums->data);
    free(deque->nums);
    free(deque);
}

void extendDequeue(DynamicArrayDequeue* deque) {
    int newCapacity = deque->queCapacity * deque->nums->extendRatio;
    int* extendNums = (int*)malloc(sizeof(int) * newCapacity);
    for(int i = 0; i < deque->nums->size; i++) {
        extendNums[i] = deque->nums->data[i];
    }
    free(deque->nums->data);
    deque->nums->data = extendNums;
    deque->queCapacity = deque->nums->capacity = newCapacity;
}

int capacity(DynamicArrayDequeue *deque) {
    return deque->queCapacity;
}
int size(DynamicArrayDequeue *deque) {
    return deque->queSize;
}

bool isEmpty(DynamicArrayDequeue *deque) {
    return size(deque) == 0;
}

int dequeIndex(DynamicArrayDequeue *deque, int i) {
    return i % deque->queCapacity;
}

void pushFront(DynamicArrayDequeue *deque, int num) {
    if(size(deque) == capacity(deque))
        extendDequeue(deque);
    deque->front = dequeIndex(deque, deque->front - 1);
    deque->nums->data[deque->front] = num;
    deque->queSize = ++(deque->nums->size);
}

void pushLast(DynamicArrayDequeue *deque, int num) {
    if(size(deque) == capacity(deque))
        extendDequeue(deque);
    int rear = dequeIndex(deque, deque->front + deque->queSize);
    deque->nums->data[rear] = num;
    deque->queSize = ++(deque->nums->size);
}

int peekFront(DynamicArrayDequeue* deque) {
    assert(size(deque) > 0);
    return deque->nums->data[deque->front];
}

int peekLast(DynamicArrayDequeue* deque) {
    assert(size(deque) > 0);
    int last = dequeIndex(deque, deque->front + deque->queSize - 1);
    return deque->nums->data[last];
}

int popFront(DynamicArrayDequeue* deque) {
    int val = peekFront(deque);
    deque->front = dequeIndex(deque, deque->front + 1);
    deque->queSize = --(deque->nums->size);
    return val;
}
int popLast(DynamicArrayDequeue* deque) {
    deque->queSize = --(deque->nums->size);
    return peekLast(deque);
}

int *toArray(DynamicArrayDequeue* deque) {
    int *arr = (int*)malloc(sizeof(int) * size(deque));
    int j = deque->front;
    for(int i = 0; i < size(deque); i++) {
        arr[i] = deque->nums->data[j % deque->queCapacity]; //注意取模
        j++;
    }
    return arr;
}
