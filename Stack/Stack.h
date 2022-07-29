#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
typedef int STDataType;

typedef struct Stack
{
    STDataType* a; //数组指针
    int top; //栈顶是第几个，栈顶下一个的下标（初始为0时）
    int capacity; //整个数组容量多少
}ST;
void StackInit(ST* ps);
void StackDestroy(ST* ps);
void StackPush(ST* ps,STDataType x)
void StackPop(ST* ps);
STDataType StackTop(ST* ps);
int StackSize(ST* ps);
bool StackEmpty(ST* ps);
