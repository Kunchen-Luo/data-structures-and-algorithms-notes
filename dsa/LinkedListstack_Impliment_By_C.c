#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//构造链表
typedef struct ListNode{
    int val;
    struct ListNode* next;
}ListNode;
//构造栈
typedef struct Linkedliststack{
    ListNode* top;    //头节点构成栈顶
    int size;
}Linkedliststack;
//构造函数
Linkedliststack* newLinkedliststack(){
    Linkedliststack *s = malloc(sizeof(Linkedliststack));
    s->top = NULL;
    s->size = 0;
    return s;
}
//析构函数
void deLinkedListstack(Linkedliststack *s){
    while(s->top){
        ListNode *n = s->top->next;
        free(s->top);
        s->top = n;
    }
    free(s);
}
//获取栈的长度
int size(Linkedliststack* s){
    return s->size;
}
//判断栈是否为空
bool isEmpty(Linkedliststack *s){
    return size(s) == 0;
}
//元素入栈
void push(Linkedliststack *s, int num){
    ListNode *node = malloc(sizeof(ListNode));
    node->next = s->top;
    node->val = num;
    s->top = node;
    s->size--;
}
//访问栈顶元素
int peek(Linkedliststack *s){
    if(s->size == 0){
        printf("The Stack is Empty");
        return -1;
    }
    return s->top->val;
}
//元素出栈
int pop(Linkedliststack *s){
    int val = s->top->val;
    ListNode *temp = s->top;
    s->top = s->top->next;
    free(temp);
    s->size--;
    return val;
}
int main(){
    Linkedliststack *s = newLinkedliststack();
    for(int i = 0; i < 99; i++){
        push(s, i);
    }
    pop(s);
    printf("%d\n", peek(s));
}
