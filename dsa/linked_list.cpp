#include <iostream>
#include <sstream>
/* while 循环（两次更新） */
int whileLoopII(int n) {    //迭代
    int res = 0;
    int i = 1; // 初始化条件变量
    // 循环求和 1, 4, 10, ...
    while (i <= n) {
        res += i;
        // 更新条件变量
        i++;
        i *= 2;
    }
    return res;
}
int forloop(int n) {    //注意for循环与while循环的区别
    int res = 0;
    for(int i = 1; i <= n; i++){
        res += i;
        i *= 2;
    }
    return res;
}
std::string nestedforloop(int n) {
    std::ostringstream res;
    for(int i = 0; i <= n; ++i) {
        for(int j = 0; j <= n; j++) {
            res << "(" << i << "," << j << ")" <<" ";
        }
    }
    return res.str();
}
// 1.
int recur(int n){   // 递归
    int res = 0;
    if(n == 1){
        return 1;
    }
    res = recur(n-1);
    return res + n;
}
int tailrecur(int n, int res){ //尾递归，在每次递的过程中累加结果
    if(n == 0)return res;
    return tailrecur(n-1, res + n);
}
int fib(int n){ // 数递归
    if(n == 1 || n == 2) return n - 1;
    // 斐波那契数列满足： f(n) = f(n-1) + f(n-2)
    int res = fib(n - 1) + fib(n - 2);
    return res;
}
// 2.递归是通过不断调用自身来解决问题，通过将大问题逐步分解为小问题来解决
//      递归可分为递和归两个过程
//      递：通过不断调用自身来不断深入，通常传入比自身小或简化的参数，直到终止条件
//      归：达到终止条件后逐层返回，汇聚每一层的结果
//  例如：斐那契数列的第 n 项f(n)可分解为 f(n) = f(n-1) + f(n-2)
//       f(n-1)分解为 f(n-2) + f(n-3),f(n-2)分解为 f(n-3) + f(n-4),以此类推
//       直到达到终止条件：n = 1 或 n = 2,f(n) = 1, f(n) = 2
//       然后逐层返回，累加每一层的结果
//       例如：f(4) = f(3) + f(2) = (f(2) + f(1)) + 1 = 2 + 1 = 3
//  每次递归时系统会给递归函数分配一个新的栈帧，用于保存本次调用的参数、局部变量、调用的返回地址等信息
//  所以递归会消耗更多的内存和时间
int* extend(int* arr, int size, int enlarge){
    int* res = new int[size + enlarge];
    for(int i = 0; i < size; i++){
        *(res + i) = *(arr + i);
    }
    //delete[] arr;
    return res;
}
//构建链表 C语言
typedef struct Listnode{
    int val;
    struct Listnode* next;
}Listnode;
//构造函数
Listnode* newListnode(int val) {
    Listnode* node = (Listnode*)malloc(sizeof(Listnode))    ;
    node -> val = val;
    node -> next = NULL;
    return node;
}
//构建链表C++
struct listnode {
    int val;
    listnode* next;
    listnode(int x) : val(x), next(nullptr) {}
};
//插入节点
void insert(listnode* n0, listnode* p){
    p->next = n0->next;
    n0->next = p;
}
//删除节点
void remove(listnode* n0) {     //n0 为要删除的节点的前一个前一个节点
    if(n0->next == nullptr) return;
   listnode* p = n0->next;
   n0->next = p->next;
   delete p;
}
//访问节点
listnode* access(listnode* head, int index){
    for(int i = 0; i < index; i++){
        if(head->next == nullptr)
            return nullptr;
        head = head->next;
    }
    return head;
}
//查找节点
int find(listnode* head, int target){
    int index = 0;
    while(head != nullptr){
        if(head->val == target)
            return index;
        index++;
        head = head->next;
    }
    return -1;  //not found
}
//双向链表
struct doublistnode{
    int val;
    doublistnode* next;
    doublistnode* prev;
    doublistnode(int x) : val(x), next(nullptr), prev(nullptr) {}
};
int main(){
    // int n = 10;
    // //int result = whileLoopII(n);
    // int result = forloop(n);
    // std::cout << result << std::endl;
    // int n = 10;
    // std::cout << nestedforloop(n) << std::endl;
    // std::cout << recur(10) << std::endl;
    // std::cout << tailrecur(10, 0) << std::endl;
    // std::cout << fib(10) << std::endl;
    // int arr[5] = {1, 2, 3, 4, 5};    //数组扩容
    // int enlarge = 5;
    // int* extendedarr = extend(arr, 5, enlarge);
    // for(int i = 5; i < 10; i++){
    //     *(extendedarr + i) = i + 1;
    // } 
    // for(int i = 0; i < 10; i++){
    //     std::cout << *(extendedarr + i) << " ";
    // }
    // std::cout << std::endl;
    // delete[] extendedarr;
    //构建链表 1->3->2->5->4
    //初始化链表
    // Listnode* n0 = newListnode(1);
    // Listnode* n1 = newListnode(3);
    // Listnode* n2 = newListnode(2);
    // Listnode* n3 = newListnode(5);
    // Listnode* n4 = newListnode(4);
    // n0->next = n1;
    // n1->next = n2;
    // n2->next = n3;
    // n3->next = n4;
    // std::cout << n0->val << "->" << n1->val << "->" << n2->val << "->" << n3->val << "->" << n4->val << std::endl;
    listnode* n0 = new listnode(1); //new的作用是分配堆内存
    listnode* n1 = new listnode(3);
    listnode* n2 = new listnode(2);
    listnode* n3 = new listnode(5);
    listnode* n4 = new listnode(4);
    n0->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    // std::cout << n0->val << "->" << n1->val << "->" << n2->val << "->" << n3->val << "->" << n4->val << std::endl;
    // //链表的插入，将节点 p 插入 n1 和 n2之间
    // listnode* p = new listnode(6);
    // insert(n1, p);
    // std::cout << n0->val << "->" << n1->val << "->" << p->val << "->" << n2->val << "->" << n3->val << "->" << n4->val << std::endl;
    // //删除节点 p
    // remove(p);
    // std::cout << n0->val << "->" << n1->val << "->" << n2->val << "->" << n3->val << "->" << n4->val << std::endl;
    //访问节点
    //std::cout << access(n0, 3)->val <<std::endl;
    //查找节点
    //std::cout << find(n0, 5) << std::endl;

}