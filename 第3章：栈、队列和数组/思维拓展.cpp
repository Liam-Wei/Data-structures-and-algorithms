#include <iostream>
using namespace std;
#define MAXSIZE 100

//定义栈结构
typedef struct
{
    int data[MAXSIZE]; //保存普通元素
    int data_min[MAXSIZE]; //保存当前栈最小值
    int top = -1; //栈针
    int top_min = -1;
} Stack;

//判断栈是否为空
bool EmptyStack(Stack s)
{
    if (s.top == -1)
    {
        return true;
    }
    return false;
}

//判断栈是否溢出
bool FullEmpty(Stack s)
{
    if (s.top == MAXSIZE)
    {
        return true;
    }
    return false;
}

//压栈
void Push(Stack &s, int x)
{
    if (!FullEmpty(s))
    {
        //如果最小值栈为空，直接将当前元素压栈
        if (s.top_min == -1)
        {
            s.data_min[++s.top_min] = x;
        }
        //如果当前值小于辅助栈的栈顶元素，将其压入辅助栈
        else if (x < s.data_min[s.top_min])
        {
            s.data_min[++s.top_min] = x;
        }
        //将当前值压入主栈
        s.data[++s.top] = x;
    }
}

//弹栈
int Pop(Stack &s)
{
    if (!EmptyStack(s))
    {
        //如果辅助栈的栈顶元素等于主栈的栈顶元素，二者全部弹出
        if (s.data[s.top] == s.data_min[s.top_min])
        {
            s.top--;
            s.top_min--;
            return s.data[s.top];
        }
        //否则将主栈元素弹出
        else
        {
            return s.data[s.top--];
        }
    }
    exit(0);
}

//获得栈中最小值
int min(Stack s)
{
    if (s.top_min == -1)
    {
        cout << "当前栈为空" << endl;
        exit(0);
    }
    //返回辅助栈的栈顶元素
    return s.data_min[s.top_min];
}
int main()
{
    Stack s;
    Push(s, 2);
    Push(s, 3);
    cout << min(s) << endl;
    Push(s, 1);
    cout << min(s) << endl;
    Pop(s);
    cout << min(s) << endl;
    Pop(s);
    cout << min(s) << endl;
}