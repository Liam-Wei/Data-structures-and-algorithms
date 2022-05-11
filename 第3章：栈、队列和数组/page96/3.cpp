#include <iostream>
using namespace std;
#define MAXSIZE 100

//定义栈
typedef struct
{
    double data[MAXSIZE];
    int top1 = -1;
} Stack;

//判断栈是否为空
bool StackEmpty(Stack s)
{
    if (s.top1 == -1)
    {
        return true;
    }
    return false;
}

//判断栈是否溢出
bool StackOverflow(Stack s)
{
    if (s.top1 >= MAXSIZE)
    {
        return true;
    }
    return false;
}

//压栈
void Push(Stack &s, double x)
{
    if (!StackOverflow(s))
    {
        s.data[++s.top1] = x;
    }
    else
    {
        cout << "当前栈已满" << endl;
    }
}

//弹栈
double Pop(Stack &s)
{

    if (StackEmpty(s))
    {
        cout << "当前栈已空" << endl;
        return '\0';
    }
    else
    {
        return s.data[s.top1--];
    }
}

//利用栈实现递归
double RecursionToStack(int n, double x)
{
    Stack s; //初始化一个栈，用于保存对应编号n

    double fv1 = 1, fv2 = 2 * x; //n=0,n=1的初始值

    //n=0情况
    if (n == 0)
    {
        return fv1;
    }

    //n=1情况
    else if (n == 1)
    {
        return fv2;
    }

    //n>1递归情况
    for (int i = n; i >= 2; i--)
    {
        Push(s, i); //将对应编号压入栈中，越上面越先算，栈顶为2
    }

    //计算p2，压入栈中，再计算p3压入栈中
    while (!StackEmpty(s))
    {
        double no = Pop(s); //弹出对应编号n
        //将计算好的Pn再次压入栈中
        Push(s, 2 * x * fv2 - 2 * (no - 1) * fv1);
        fv1 = fv2; //fv2的值赋予fv1
        fv2 = Pop(s); //fv2的值则为刚才新计算出压入栈顶的值
    } 

    return fv2;
}

int main()
{
    int n = 5;
    double x = 4;
    cout << RecursionToStack(n, x) << endl;
}