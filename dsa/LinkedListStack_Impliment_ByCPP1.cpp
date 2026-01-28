#include <stdexcept>
#include <vector>

class LinkedListStack {
    private:
        struct ListNode{
            int val;
            struct ListNode* next;
            ListNode(int x): val(x), next(nullptr){}
        };
        
        ListNode* stackTop;
        int stkSize;
        
        void freeMemoryLinkedList(ListNode* head){
            while(head){
                ListNode* temp = head;
                head = head->next;
                delete temp;
            }
        }
        
    public:
        LinkedListStack(): stackTop(nullptr), stkSize(0){};
        
        ~LinkedListStack(){
            freeMemoryLinkedList(stackTop);
        }

        int size(){
            return stkSize;
        }

        bool isEmpty(){
            return size() == 0;
        }

        void push(int num){
            ListNode* node = new ListNode(num);
            node->next = stackTop;
            stackTop = node;
            ++stkSize;
        }

        int top(){
            if(isEmpty())
                throw std::out_of_range("The Stack is Empty");
                return stackTop->val;
        }

        int pop(){
            int num = top();
            ListNode* temp = stackTop;
            stackTop = stackTop->next;
            delete temp;
            --stkSize;
            return num;
        }

        std::vector<int> toVetor() {
            ListNode* node = stackTop;
            std::vector<int> res(size());
            for(int i = size() - 1; i >= 0; --i){
                res[i] = node->val;
                node = node->next;
            }
            return res;
        }
};