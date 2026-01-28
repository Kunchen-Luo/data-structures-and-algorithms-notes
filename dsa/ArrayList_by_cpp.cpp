#include <stdexcept>
#include <vector>
#include <iostream>
class MyList {
    private:
        int* arr;
        int arrCapacity = 10;
        int arrSize = 0;
        int extendRatio = 2;

    public:
        MyList() {
            arr = new int[arrCapacity];
        }

        ~MyList() {
            delete[] arr;
        }

        int size() {
            return arrSize;
        }

        int capacity() {
            return arrCapacity;
        }

        int get(int index) {
            if(index < 0 || index >= arrSize)
                throw std::out_of_range("索引越界");
            return arr[index];
        }

        void set(int index, int num) {
            if(index < 0 || index >= arrSize)
                throw std::out_of_range("索引越界");
            arr[index] = num;
        }

        void extendCapacity() {
            int newCapacity = capacity() * extendRatio;
            int* temp = arr;
            int* extend  = new int[newCapacity];
            for(int i = 0; i < size(); i++) {
                extend[i] = arr[i];
            }
            delete[] temp;
            arr = extend;
            arrCapacity = newCapacity;
        }

        void add(int num) {
            if(size() == capacity())
                extendCapacity();
            arr[size()] = num;
            arrSize++;
        }

        void insert(int index, int num) {
            if(index < 0 || index >= size())
                throw std::out_of_range("索引越界");
            if(size() == capacity())
                extendCapacity();
            for(int i = size(); i > index; i--) {
                arr[i] = arr[i - 1];
            }
            arr[index] = num;
            arrSize++;
        }

        int removeItem(int index) {
            if(index < 0 || index >= size())
                throw std::out_of_range("索引越界");
            int num = arr[index];
            for(int i = index; i < size() - 1; i++) {
                arr[i] = arr[i + 1];
            }
            arrSize--;
            return num;
        }

        std::vector<int> toVector() {
            std::vector<int> vec(size());
            for(int i = 0; i < size(); i++) {
                vec[i] = arr[i];
            }
            return vec;
        }        
};
int main() {
    // MyList List;
    // for(int i = 0; i < 100; i++) {
    //     List.add(i);
    // }
    // std::cout << List.capacity() << std::endl;
    // List.removeItem(99);
    // std::cout << List.size() << std::endl;
    // List.insert(50,1);
    // std::cout << List.size() << List.get(98) <<std::endl;
    //下面写法错误
    // MyList* p;
    // for(int i = 0; i < 100; i++) {
    //     p->add(i);
    // }
    // for(int i = 0; i< 100; i++) {
    //     std::cout << p->get(i);
    // }
}