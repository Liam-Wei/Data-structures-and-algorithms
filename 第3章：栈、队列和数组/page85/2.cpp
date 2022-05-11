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

//判断队列是否为空
bool IsEmpty(SqQueue Q)
{
    if (Q.front == Q.rear)
    {
        return true;
    }
    return false;
}

//判断队列是否满
bool IsFull(SqQueue Q)
{
    if (Q.rear == MAXSIZE)
    {
        return true;
    }
    return false;
}

//进队
bool EnQueue(SqQueue &Q, int x)
{
    if (IsFull(Q))
    {
        return false;
    }
    Q.data[Q.rear] = x;
    Q.rear++;
    return true;
}

//出队
bool DeQueue(SqQueue &Q, int &x)
{
    if (IsEmpty(Q))
    {
        return false;
    }
    x = Q.data[Q.front];
    Q.front++;
    return true;
}

void Push(Stack &s, int value)
{
    s.data[++s.top1] = value;
}

int Pop(Stack &s)
{

    if (s.top1 == -1)
    {
        cout << "当前栈已空" << endl;
        return -1;
    }
    else
    {
        return s.data[s.top1--];
    }
}

//输出队列元素
void Print(SqQueue Q)
{
    for (int i = Q.front; i < Q.rear; i++)
    {
        cout << Q.data[i] << '\t';
    }
    cout << endl;
}

void ReverseQueue(SqQueue &Q, Stack &s)
{
    //将队列中的元素出队压入栈中
    while (Q.front != Q.rear)
    {
        int value;
        DeQueue(Q, value);
        Push(s, value);
    }

    Q.front = Q.rear = 0;

    //将栈中元素弹出入队
    while (s.top1 != -1)
    {
        int value = Pop(s);
        EnQueue(Q, value);
    }
}

int main()
{
    SqQueue Q;
    Stack s;
    EnQueue(Q, 1);
    EnQueue(Q, 2);
    EnQueue(Q, 3);

    Print(Q);
    ReverseQueue(Q, s);
    Print(Q);
}