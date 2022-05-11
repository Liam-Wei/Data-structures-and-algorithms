#include <iostream>
using namespace std;
#define MAXSIZE 3

//定义循环队列
typedef struct
{
    int data[MAXSIZE];
    int front = 0, rear = 0;
} SqQueue;

//定义栈
typedef struct
{
    int data[MAXSIZE];
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
void Push(Stack &s, int x)
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
void Pop(Stack &s, int &x)
{

    if (StackEmpty(s))
    {
        cout << "当前栈已空" << endl;
        return;
    }
    else
    {
        x = s.data[s.top1--];
    }
}

//入队
void Enqueue(Stack &s1, Stack &s2, int x)
{
    //如果栈s1没有满，将x压入x1
    if (!StackOverflow(s1))
    {
        Push(s1, x);
        return;
    }
    //如果s1满了，同时s2不是空的，表明此时队列已满
    else if (StackOverflow(s1) && !StackEmpty(s2))
    {
        cout << "当前队列已满" << endl;
        return;
    }
    //如果s1满，此时s2为空，队列不满，将s1中元素压入s2
    else if (StackOverflow(s1) && StackEmpty(s2))
    {
        int value;
        while (!StackEmpty(s1))
        {
            Pop(s1, value);
            Push(s2, value);
        }
        Push(s1, x);
    }
}

//出队
void Dequeue(Stack &s1, Stack &s2, int &x)
{
    //如果栈s2不空，直接出队
    if (!StackEmpty(s2))
    {
        Pop(s2, x);
    }
    //如果栈s2空且s1为空，表明队列为空
    else if (StackEmpty(s1))
    {
        cout << "当前队列为空" << endl;
        return;
    }
    //如果栈s2空且s1不空，将s1中元素弹出压入s2中
    else
    {
        int value;
        while (!StackEmpty(s1))
        {
            Pop(s1, value);
            Push(s2, value);
        }
        Pop(s2, x);
    }
}

//判断队列是否为空
void QueueEmpty(Stack s1, Stack s2)
{
    if (StackEmpty(s1) && StackEmpty(s2))
    {
        cout << "当前队列为空" << endl;
    }
}

int main()
{
    Stack s1, s2;
    int x = 0;
    QueueEmpty(s1, s2);
    Enqueue(s1, s2, 1);
    Enqueue(s1, s2, 2);
    Dequeue(s1, s2, x);
    cout << x << endl;
    Enqueue(s1, s2, 3);
    Dequeue(s1, s2, x);
    cout << x << endl;
    Dequeue(s1, s2, x);
    cout << x << endl;
    QueueEmpty(s1, s2);
}