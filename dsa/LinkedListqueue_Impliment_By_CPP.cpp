#include <stdexcept>
#include <vector>
#include <iostream>
class LinkedListqueue {
    private:
        typedef struct ListNode {
            int val;
            struct ListNode* next;
            ListNode(int x): val(x), next(nullptr){};
        } ListNode;

        void freeMemoryLinkedList(ListNode* front) {
            while(front != nullptr) {
                ListNode* temp = front;
                front = front->next;
                delete temp;
            }
        }

        ListNode *front, *rear;
        int queSize;

    public:
        LinkedListqueue() {
            front = nullptr;
            rear = nullptr;
            queSize = 0;
        }

        ~LinkedListqueue() {
            freeMemoryLinkedList(front);
        }

        int size() {
            return queSize;
        }

        bool isEmpty() {
            return size() == 0;
        }

        void push(int num) {
            ListNode* node = new ListNode(num);
            if (front == nullptr) {
                front = node;
                rear = node;
                queSize++;
            }
            else {
                rear->next = node;
                rear = node;
                queSize++;
            }
        }

        int peek() {
            if(size() == 0)
                throw std::out_of_range("队列为空");
            return front->val;
        }

        int pop() {
            int res = front->val;
            ListNode* temp = front;
            front = front->next;
            delete temp;
            queSize--;
            return res;
        }

        std::vector<int> tovector() {
            ListNode* node = front;
            std::vector<int> res(size());
            int i;
            for(i = 0; i < queSize; i++) {
                res[i] = node->val;
                node = node->next;
            }
            return res;
        }
};  
int main() {
    LinkedListqueue que;
    for(int i = 0; i < 100; i++) {
        que.push(i);
    }
    for(int i = 0; i < 100; i++) {
        std::cout << que.pop() << " ";
    }
}