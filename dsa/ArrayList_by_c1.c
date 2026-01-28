#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
typedef struct {
    int* arr;
    int capacity;
    int size;
    int extendRatio;
} MyList;

MyList* newMyList() {
    MyList* nums = malloc(sizeof(MyList));
    nums->capacity = 10;
    nums->arr = malloc(sizeof(int) * nums->capacity);
    nums->size = 0;
    nums->extendRatio = 2;
    return nums;    //返回对象的指针
}

void deMyList(MyList* nums) {
    free(nums->arr);
    free(nums);
}

int size(MyList* nums) {
    return nums->size;
}

int capacity(MyList* nums) {
    return nums->capacity;
}

int get(MyList* nums, int index) {
    assert(index >= 0 && index < size(nums));
    return nums->arr[index];
}

void set(MyList* nums, int index, int num) {
    assert(index >= 0 && index < size(nums));
    nums->arr[index] = num;
}

void extendcapacity(MyList* nums) {
    int newcapacity = nums->capacity * nums->extendRatio;
    int* extend = malloc(sizeof(int) * newcapacity);
    int* temp = nums->arr;
    for(int i = 0; i < size(nums); i++) {
        extend[i] = nums->arr[i];
    }
    free(temp);
    nums->arr = extend;
    nums->capacity = newcapacity;
}

void add(MyList* nums, int num) {
    if(size(nums) == capacity(nums))
        extendcapacity(nums);
    nums->arr[size(nums)] = num;
    nums->size++;
}

void insert(MyList* nums, int index, int num) {
    assert(index >= 0 && index < size(nums));
    if(nums->capacity == nums->size)
        extendcapacity(nums);
    for(int i = size(nums); i > index; --i) {
        nums->arr[i] = nums->arr[i - 1];
    }
    nums->arr[index] = num;
    nums->size++;
}

int removeItem(MyList* nums, int index) {
    assert(index >= 0 && index < size(nums));
    int num = nums->arr[index];
    for(int i = index; i < size(nums) - 1; i++){
        nums->arr[i] = nums->arr[i + 1];
    }
    nums->size--;
    return num;
}

int* toArray(MyList* nums) {
    return nums->arr;
}
int main(){
    MyList* nums = newMyList();
    for(int i = 0; i < 100; i++){
        add(nums, i);
        printf("%d ", size(nums));
    }
    printf("\n");
    printf("%d\n", capacity(nums));
    
}