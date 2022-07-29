#include "Stack.h"

void StackInit(ST* ps)
{
    assert(ps);
    ps->a = NULL;
    //如果初始化的时候top=0， 那top指向的就是栈顶数据的下一位
    //如果初始化的时候top=-1， 那top指向的就是栈顶数据
    ps->top = 0;//ps->top =-1; //此为0，先插入/删除，在top++
    ps->capacity = 0;
}
//销毁整个栈
void StackDestory(ST* ps)
{
    assert(ps);
    free(ps->a);
    ps->a = NULL;
    ps->top = ps->capacity = 0;
}
//从栈顶插入数据
void StackPush(ST* ps, STDataType x)
{
    assert(ps);
    if (ps->top == ps->capacity)
    {
        int newCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
        STDataType* tmp = realloc(ps->a,sizeof(STDataType) * newCapacity); //若ps->a为NULL就跟malloc一样
        if (tmp == NULL)
        {
            printf("realloc fail\n");
            exit(-1);
        }
        ps->a = tmp;
        ps->capacity = newCapacity;
    }
    ps->a[ps->top] = x;
    ps->top++;
}
//删除栈顶的数据
void StackPop(ST* ps)
{
    assert(ps);
    //assert(ps->top > 0);////top>0 就表示不为空，防止再次调用删除函数
    assert(!StackEmpty(ps));
    ps->top--;
}
//取栈顶的数据，取了还是在，并没有删除
STDataType StackTop(ST* ps)
{
    assert(ps);
    //assert(ps->top > 0); //top>0 就表示不为空
    assert(!StackEmpty(ps));
    return ps->a[ps->top -1];
}
//返回目前栈的大小
int StackSize(ST* ps)
{
    assert(ps);
    return ps->top;
}
//返回是否为空
bool StackEmpty(ST* ps)
{
    return ps->top == 0;//若等于0，那就是ture，为空
}


//栈打印
/*while (!StackEmpty(&st))
{
    printf("%d ", StackTop(&st));//取出栈顶数据
    StackPop(&st); //删除栈顶数据
)
StackDestroy(&st);//数据删完了也需要销毁空间，不然一直不会释放*/
