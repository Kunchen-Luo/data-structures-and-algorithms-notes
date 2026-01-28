#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
typedef struct {
    int* elements;
    int capacity;
    int extendRatio;
} ArrayList;
//ArrayList 构造函数
ArrayList* newArrayList() {
    ArrayList* data = malloc(sizeof(ArrayList));
    data->capacity = 10;
    data->extendRatio = 2;
    data->elements = malloc(sizeof(int) * data->capacity);
    return data;
}

typedef struct {
    ArrayList* data;
    int size;
} ArrayStack;
//ArrayStack 构造函数
ArrayStack* newArrayStack() {
    ArrayStack* stack = malloc(sizeof(ArrayStack));
    stack->size = 0;
    stack->data = newArrayList();
    return stack;
}
//析构函数
void daArrayListstack(ArrayStack* stack) {
    free(stack->data->elements);
    free(stack->data);
    free(stack);
}

int size(ArrayStack* stack) {
    return stack->size;
}

bool isEmpty(ArrayStack* stack) {
    return stack->size == 0;
}

void extendcapacity(ArrayStack* stack) {
    int newcapacity = stack->data->capacity * stack->data->extendRatio;
    int* extend = malloc(sizeof(int) * newcapacity);
    for(int i = 0; i < size(stack); i++) {
        extend[i] = stack->data->elements[i];
    }
    free(stack->data->elements);
    stack->data->elements = extend;
    stack->data->capacity = newcapacity;
}

void push(ArrayStack* stack, int num) {
    if(stack->size == stack->data->capacity)
        extendcapacity(stack);
    stack->data->elements[size(stack)] = num;
    stack->size++;
}

int peek(ArrayStack* stack) {
    if(stack->size == 0) {
        printf("栈为空");
        exit(EXIT_FAILURE);
    }
    return stack->data->elements[size(stack) - 1];
}

int pop(ArrayStack* stack) {
    int num = peek(stack);
    stack->size--;
    return num;
}
int main() {
    ArrayStack* stk = newArrayStack();
    for(int i = 0; i < 100; i++) {
        push(stk, i);
    }
    for(int i = 0; i < 100; i++) {
        printf("%d ", pop(stk));
    }
    printf("\n");
    printf("%d\n", size(stk));
}