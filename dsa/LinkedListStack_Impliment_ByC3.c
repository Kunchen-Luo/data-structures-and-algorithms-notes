#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct ListNode{
    int val;
    struct ListNode* next;
}ListNode;
typedef struct{
    ListNode* top;
    int size;
}LinkedListstack;
//构造函数
LinkedListstack* newLinkedListstack(){
    LinkedListstack* s = malloc(sizeof(LinkedListstack));
    s->top = NULL;
    s->size = 0;
    return s;
}
//析构函数
void deLinkedListstack(LinkedListstack* s){
    while(s->top){
        ListNode* n = s->top->next;
        free(s->top);
        s->top = n;
    }
}
//获取栈的长度
int size(LinkedListstack* s){
    return s->size;
}
//判断栈是否为空
bool isEmpty(LinkedListstack* s){
    return size(s) == 0;
}
//元素入栈
void push(LinkedListstack* s, int num){
    ListNode* node = malloc(sizeof(ListNode));
    node->next = s->top;
    node->val = num;
    s->top = node;
    s->size++;
}
//访问栈顶
int peek(LinkedListstack* s){
    if(s->size == 0){
        printf("The Stack is Empty");
        return -1;
    }
    return s->top->val;
}
//元素出栈
int pop(LinkedListstack* s){
    int val = s->top->val;
    ListNode* temp = s->top;
    s->top = s->top->next;
    free(temp);
    s->size--;
    return val;
}
int main(){
    LinkedListstack* s = newLinkedListstack();
    for(int i = 1; i < 100; i++){
        push(s, i);
    }
    for(int i = 1; i < 100; i++){
        printf("%d ", pop(s));
    }
    printf("\n");
    // printf("%d\n", size(s));
    if(isEmpty(s))
        printf("The Stack is Empty\n");
    else
        printf("%d\n", size(s));
}
