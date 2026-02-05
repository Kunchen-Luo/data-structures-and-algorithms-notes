#include <stdexcept>
#include <vector>
class LinkedListDeque {
    private:
        struct DoublyListNode {
            int val;
            DoublyListNode *prev, *next;
            DoublyListNode(int val) : val(val), prev(nullptr), next(nullptr) {};
        };

        DoublyListNode *front, *rear;
        int queSize;

    public:
        LinkedListDeque() : front(nullptr), rear(nullptr), queSize(0) {};

        ~LinkedListDeque() {
            while(front->next != nullptr) {
                DoublyListNode *temp = front;
                front = front->next;
                delete temp;
            }
        }

        int size() {
            return queSize;
        }

        bool isEmpty() {
            return size() == 0;
        }

        void push(int num, bool isFront) {
            DoublyListNode* node = new DoublyListNode(num);
            if(isEmpty()) {
                front = rear = node;
            }
            else if(isFront) {
                front->prev = node;
                node->next = front;
                front = node;
            }
            else {
                rear->next = node;
                node->prev = rear;
                rear = node;
            }
        }

        void pushFront(int num) {
            push(num, true);
        }

        void pushLast(int num) {
            push(num, false);
        }

        int peekFront() {
            if(isEmpty()) 
                throw std::out_of_range("双向队列为空");
            return front->val;
       }

        int peekLast() {
            if(isEmpty())
                throw std::out_of_range("双向队列为空");
            return rear->val;
       }

        int pop(bool isFront) {
            int val;
            if(isFront) {
                val = peekFront();
                DoublyListNode *fNext = front->next;
                if(fNext) {
                    fNext->prev = nullptr;
                    front->next = nullptr;
                }
                delete front;
                front = fNext;
            }
            else {
                val = peekLast();
                DoublyListNode *rPrev = rear->prev;
                if(rPrev) {
                    rPrev->next = nullptr;
                    rear->prev = nullptr;
                }
                delete rear;
                rear = rPrev;
            }
            queSize--;
            return val;
       }

       std::vector<int> toVector() {
            DoublyListNode *node = front;
            std::vector<int> res(size());
            for(int i =0; i < res.size(); i++) {
                res[i] = node->val;
                node = node->next;
            }
            return res;
       }
};