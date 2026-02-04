#include <stdexcept>
#include <vector>
#include <iostream>
class LinkedListQueue {
    private:
        struct ListNode {
            int val;
            ListNode* next;
            ListNode(int x): val(x), next(nullptr){}; 
        };

        ListNode *front, *rear;
        int queSize;

        void freeMemoryLinkedListQueue(ListNode* front) {
           while(front->next != nullptr) {
            ListNode* temp;
            front = front->next;
            delete temp;
           }
        }
    public:
        LinkedListQueue() {
            front = nullptr;
            rear = nullptr;
            queSize = 0;
        }
        ~LinkedListQueue() {
            freeMemoryLinkedListQueue(front);
        }

        int size() {
            return queSize;
        }

        bool isEmpty() {
            return queSize == 0;
        }

        int peek() {
            if(size() == 0)
                throw std::out_of_range("队列为空");
            return front->val;
        }

        void push(int num) {
            ListNode* node = new ListNode(num);
            if(front == nullptr) {
                front = node;
                rear = node;
            }
            else {
                rear->next = node;
                rear = node;
            }
            queSize++;
        }

        int pop() {
            int num = peek();
            ListNode* temp = front;
            front = front->next;
            delete temp;
            queSize--;
            return num;
        }

        std::vector<int> toVector() {
            std::vector<int> res(size());
            ListNode* node = front;
            for(int i = 0; i < res.size(); i++) {
                res[i] = node->val;
                node = node->next;
            }
            return res;
        }
};

int main(){
    LinkedListQueue que;
    for(int i = 1; i < 100; ++i){
        que.push(i);
    }
    for(int i = 1; i < 100; ++i){
        std::cout << que.pop() << " ";
    }
    std::cout << que.size() << std::endl;
}