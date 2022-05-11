#include <iostream>
using namespace std;
#define MAXSIZE 100

//定义栈
typedef struct
{
    char data[MAXSIZE];
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
void Push(Stack &s, char x)
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
char Pop(Stack &s)
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

//实现火车调度
void TrainSchedule(char *str)
{
    Stack s;          //初始栈，用于保存H
    int i = 0, k = 0; //定义两个变量，i用于遍历，k用于调度S

    while (str[i] != '\0')
    {
        //如果是H，则将其入栈，等待调度
        if (str[i] == 'H')
        {
            Push(s, str[i]);
        }
        //如果是S，直接将其填补到前面
        else
        {
            str[k++] = str[i];
        }
        i++;
    }

    //将所有H拼在S后面
    while (!StackEmpty(s))
    {
        str[k++] = Pop(s);
    }
}

int main()
{
    char str[] = "HSHHSSHHHS";
    TrainSchedule(str);
    cout << str << endl;
}