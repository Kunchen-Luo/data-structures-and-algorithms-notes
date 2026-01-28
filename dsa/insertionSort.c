#include <stdio.h>
void insertionsort(int* nums, int size){
    for(int i = 1; i < size; i++){
        int base = nums[i], j = i - 1;
        while(j >= 0 && nums[j] < base){
            nums[j + 1] = nums[j];
            --j;
        }
        nums[j + 1] = base;
    }
}
int main(){
    int arr[11];
    for(int i = 0; i < 11; i++){
        scanf("%d", arr + i);
    }
    insertionsort(arr, 11);
    for(int i = 0; i < 11; i++){
        printf("%d ", *(arr + i));
    }
    return 0;
}