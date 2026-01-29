#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <stdio.h>
typedef struct {
    int *nums;
    int front;
    int queSize;
    int queCapacity;
} Arrayqueue;

Arrayqueue* newArrayqueue(int capacity) {
    Arrayqueue* queue = (Arrayqueue*)malloc(sizeof(Arrayqueue));
    queue->queCapacity = capacity;
    queue->nums = (int*)malloc(sizeof(int) * queue->queCapacity);
    queue->front = queue->queSize = 0;
    return queue;
}

void deArrayqueue(Arrayqueue* queue) {
    free(queue->nums);
    free(queue);
}

int capacity(Arrayqueue* queue) {
    return queue->queCapacity;
}

int size(Arrayqueue* queue) {
    return queue->queSize;
}

bool isEmpty(Arrayqueue* queue) {
    return queue->queSize == 0;
}

int peek(Arrayqueue* queue) {
    assert(queue->queSize != 0);
    return queue->nums[queue->front];
}

void push(Arrayqueue* queue, int num) {
    if(size(queue) == capacity(queue)) {
        printf("队列已满");
        return;
    }
    int rear = (queue->front + queue->queSize) % queue->queCapacity;
    queue->nums[rear] = num;
    queue->queSize++;
}

int pop(Arrayqueue* queue) {
    int num = peek(queue);
    queue->front = (queue->front + 1) % queue->queCapacity;
    queue->queSize--;
    return num;
}

int *toArray(Arrayqueue* queue) {
    int* res = (int*)calloc(queue->queSize, sizeof(int));
    int j = queue->front;
    for(int i = 0; i < queue->queSize; i++) {
        res[i] = queue->nums[j % queue->queCapacity];
        j++;
    }
    return res;
}

int main() {
    int capacity = 100;
    Arrayqueue* queue = newArrayqueue(capacity);
    for(int i = 0; i < 100; i++) {
        push(queue, i);
    }
    for(int i = 0; i < 50; i++) {
        pop(queue);
    }
     for(int i = 0; i < 50; i++) {
        push(queue, i);
    }
    int* arr = toArray(queue);
    for(int i = 0; i < 100; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

