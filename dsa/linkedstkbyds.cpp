#include <stdexcept>
class LinkedListStack {
private:
    // 内部数据结构
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(nullptr) {}
    };
    
    ListNode *stackTop;
    int stkSize;
    
    // 私有辅助函数：释放链表内存
    void freeMemoryLinkedList(ListNode *head) {
        while (head) {
            ListNode *temp = head;
            head = head->next;
            delete temp;  // 使用delete释放new分配的内存
        }
    }
    
    // 私有辅助函数：复制链表（用于拷贝构造函数和赋值运算符）
    ListNode* copyLinkedList(ListNode *head) {
        if (!head) return nullptr;
        
        ListNode *newHead = new ListNode(head->val);
        ListNode *current = newHead;
        head = head->next;
        
        while (head) {
            current->next = new ListNode(head->val);
            current = current->next;
            head = head->next;
        }
        
        return newHead;
    }
    
public:
    // 构造函数
    LinkedListStack() : stackTop(nullptr), stkSize(0) {}
    
    // 拷贝构造函数（深拷贝）
    LinkedListStack(const LinkedListStack &other) {
        stackTop = copyLinkedList(other.stackTop);
        stkSize = other.stkSize;
    }
    
    // 赋值运算符（深拷贝）
    LinkedListStack& operator=(const LinkedListStack &other) {
        if (this != &other) {  // 防止自赋值
            // 先释放现有内存
            freeMemoryLinkedList(stackTop);
            
            // 复制新内容
            stackTop = copyLinkedList(other.stackTop);
            stkSize = other.stkSize;
        }
        return *this;
    }
    
    // 析构函数
    ~LinkedListStack() {
        freeMemoryLinkedList(stackTop);
    }
    
    // 公共接口
    void push(int num) {
        ListNode *node = new ListNode(num);
        node->next = stackTop;
        stackTop = node;
        stkSize++;
    }
    
    int pop() {

        int num = top();
        ListNode *tmp = stackTop;
        stackTop = stackTop->next;
        delete tmp;
        stkSize--;
        return num;
    }
    
    int top() const {
        if (isEmpty()) {
            throw std::out_of_range("栈为空");
        }
        return stackTop->val;
    }
    
    bool isEmpty() const {
        return stkSize == 0;
    }
    
    int size() const {
        return stkSize;
    }
    
    // 清空栈的公共接口
    void clear() {
        freeMemoryLinkedList(stackTop);
        stackTop = nullptr;
        stkSize = 0;
    }
};