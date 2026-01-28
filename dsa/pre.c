#include <stdio.h>
#include <string.h> //使用下列函数时需要包含头文件<string.h>
#include <stdlib.h>
int main(){
    char s1[] = "abcdef";   //字符串字面量，编译器会自动在末尾添加'\0'，因此 s1 的长度为 7
    //1、strlen(char *s), 返回字符串的有效长度（不包括结束符“\0”）
    int len = strlen(s1);
    char s2[10];

    //2、strcpy(char *s1, char *s2), 将 s2 的内容复制到 s1 中，s1 的长度必须大于等于 s2 的长度
    strcpy(s1, s2);
    char s3[10] = {'\0'};
    
    //3、strncpy(char *s1, char *s2, int n), 复制 s1 的前 n 个字符到 s2 中
    strncpy(s3, s1, 3);
    //s3[3] = '\0';
    
    //4、将 s2 拼接在 s1 的末尾，s2 的首元素覆盖 s1 的'\0'
    strcat(s3, s2); 
    
    //5、strncat(char *s1, char *s2, int n), 将 s2 的前 n 个字符拼接到 s1 的末尾
    strncat(s2, s1, 3);
    
    //6、strcmp(char *s1, char *s2), 用于比较两个字符串的长度，
    //s1 比 s2 短则返回 -1，如果 s1 与 s2 完全相同则返回 0，s1 比 s2 长则返回 1； 
    //如果 s1 与 s2 的长度相等但元素不同，则比较第一个不相同字符的 ASCII码，返回 ASCII 码的差值
    int cmp = strcmp(s2, s1); 
    
    //7、比较指定长度的字符串
    cmp = strncmp(s1, s2, 3);
    
    //8、strchr(char *s, char c),查找字符串 s 中第一次出现字符 c 的位置，返回指向该字符的指针，如果未找到则返回 NULL
    char* pos = strchr(s1, 'd');
    char* pos0 = strchr(s1, 'a');
    int index = pos - pos0; //通过目标元素的指针地址和首元素的指针相减计算目标元素的索引
    
    //9、strstr(char *s1, char *s2), 
    //查找字符串 s1 的子串 s2 首次出现的位置，
    //返回指向该子串的指针（首元素的地址），如果未找到则返回NULL
    int pos = strstr(s1, s2);
    
    
    // char str[10]; //定义字符串
    // char* str = (char*)malloc(10 * sizeof(char)); //定义指针 str, malloc 申请一块连续内存，(类型*）malloc（n * sizeof(类型))；
    // fgets(str, 10, stdin);  //fgets(char *str, int n, FILE *stream)，从标准输入流读取字符串，最多读取 n-1 个字符，最后一个字符为'\0'
    // fputs(str, stdout);
    // printf("\n");
    // free(str); //释放动态分配的内存
    // int a = 0, b = 0, c = 0, d = 0;
    // scanf("%d%d%%d%d%d", &a, &b, &c, &d);
    // printf("%d %d %d %d\n", a, b, c, d);
    FILE* fp = fopen("text2.txt", "r");
    char buffer[100];
    if(fgets(buffer, sizeof(buffer), fp) != NULL)
        printf("%s", buffer);
    else
        return 1;
    int a[10] = {10};
    for(int i = 0; i < 10; i++)
        printf("%d ", a[i]);
    printf("\n");
}