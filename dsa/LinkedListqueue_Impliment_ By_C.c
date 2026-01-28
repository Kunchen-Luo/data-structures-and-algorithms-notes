#include <stdlib.h>
#include <assert.h>
typedef struct ListNode {
    int val;
    struct ListNode* next;
} ListNode;

ListNode* newListNode(int num) {
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->val = num;
    node->next = NULL;
    return node;
}

typedef struct {
    ListNode* front;
    ListNode* rear;
    int size;
} LinkedListqueue;

LinkedListqueue* newListNodequeue() {
    LinkedListqueue* queue = (LinkedListqueue*)malloc(sizeof(LinkedListqueue));
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
    return queue;
}

void deLinkedListqueue(LinkedListqueue* queue) {
    while(queue->front != NULL) {
        ListNode* temp = queue->front;
        queue->front = queue->front->next;
        free(temp);
    }
}

int size(LinkedListqueue* queue) {
    return queue->size;
}

isEmpty(LinkedListqueue* queue) {
    return size(queue) == 0;
}

void push(LinkedListqueue* queue, int num) {
    ListNode* node = newListNode(num);
    if(queue->front = NULL) {
        queue->front = node;
        queue->rear = node;
        queue->size++;
    }
    else {
        queue->rear->next = node;
        queue->rear = node;
        queue->size++;
    }
}

int peek(LinkedListqueue* queue) {
    assert(size(queue) && queue->front);
    return queue->front->val;
}

int pop(LinkedListqueue* queue) {
    int res = peek(queue);
    ListNode* temp = queue->front;
    queue->front = queue->front->next;
    free(temp);
    queue->size--;
    return res;
}

void printLinkedListqueue(LinkedListqueue* queue) {
    int* arr = malloc(sizeof(int) * size(queue));
    int i;
    ListNode* node;
    for(i = 0, node = queue->front; i < queue->size; i++) {
        arr[i] = node;
        node = node->next;
    }
    printArray(arr, queue->size);
}
