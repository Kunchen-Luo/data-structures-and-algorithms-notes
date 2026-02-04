#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <stdio.h>
typedef struct DoublyListNode {
    int val;
    struct DoublyListNode *next;
    struct DoublyListNode *prev;
} DoublyListNode;

DoublyListNode* newDoublyListNode(int num) {
    DoublyListNode* node = (DoublyListNode*)malloc(sizeof(DoublyListNode));
    node->next = NULL;
    node->prev = NULL;
    node->val = num;
    return node;
}

void deDoublyListNode(DoublyListNode* node) {
    free(node);
}

typedef struct {
    DoublyListNode* front, *rear;
    int queSize;
} LinkedListDeque;

LinkedListDeque* newLinkedListDeque() {
    LinkedListDeque* deque = (LinkedListDeque*)malloc(sizeof(LinkedListDeque));
    deque->front = NULL;
    deque->rear = NULL;
    deque->queSize = 0;
    return deque;
}

void deLinkedListDeque(LinkedListDeque* deque) {
    for(int i = 0; i < deque->queSize && deque->front != NULL; i++) {
        DoublyListNode* temp = deque->front;
        deque->front = deque->front->next;
        free(temp);
    }
}

int size(LinkedListDeque* deque) {
    return deque->queSize;
}

int isEmpty(LinkedListDeque* deque) {
    return deque->queSize == 0;
}

void push(LinkedListDeque* deque, int num, bool isFront) {
    DoublyListNode* node = newDoublyListNode(num);
    if(deque->queSize == 0) 
        deque->rear = deque->front = node;
    else if(isFront) {
        deque->front->prev = node;
        node->next = deque->front;
        deque->front = node;
    }
    else {
        deque->rear->next = node;
        node->prev = deque->rear;
        deque->rear = node;
    }
    deque->queSize++;
}

void pushFirst(LinkedListDeque* deque, int num) {
    push(deque, num, true);
}

void pushLast(LinkedListDeque* deque, int num) {
    push(deque, num, false);
}

int peekFirst(LinkedListDeque* deque) {
    assert(size(deque) && deque->front);
    return deque->front->val;
}

int peekLast(LinkedListDeque* deque) {
    assert(size(deque) && deque->rear);
    return deque->rear->val;
}
int pop(LinkedListDeque* deque, bool isFront) {
    if(deque->queSize == 0)
        return -1;
        int val;
    if(isFront) {
        val = peekFirst(deque);
        DoublyListNode* fNext = deque->front->next; 
        if(fNext) { //如果队首存在下一个元素，则需要断开队首元素的连接
            fNext->prev = NULL;
            deque->front->next = NULL;
        }
        deDoublyListNode(deque->front);
        deque->front = fNext;
    }
    else {
        val = peekLast(deque);
        DoublyListNode* rPrev = deque->rear->prev;
        if(rPrev) {
            rPrev->next = NULL;
            deque->rear->prev = NULL;
        }
        deDoublyListNode(deque->rear);
        deque->rear = rPrev;
    }
    deque->queSize--;
    return val;
}

void popFirst(LinkedListDeque* deque) {
    pop(deque, true);
}

void popLast(LinkedListDeque* deque) {
    pop(deque, false);
}
void printArray(int* arr, int n) {
    for(int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        printf(" ");
    }
    printf("\n");
}
void printLinkedListDeque(LinkedListDeque* deque) {
    int* arr = (int*)malloc(sizeof(int) * deque->queSize);
    DoublyListNode* node;
    int i;
    for(i = 0, node = deque->front; i < deque->queSize; i++) {
        arr[i] = node->val;
        node = node->next;
    }
    printArray(arr, deque->queSize);
    free(arr);
}

int main() {
    LinkedListDeque* deque = newLinkedListDeque();
    for(int i = 0; i < 100; i++) {
        pushFirst(deque, i);
    }
    // for(int i = 100; i >= 50; i--) {
    //     pushLast(deque, i);
    // }
    printLinkedListDeque(deque);
    // for(int i = 0; i < size(deque); i++) {
    //     popFirst(deque);
    // }
    printf("%d\n", size(deque));
}


