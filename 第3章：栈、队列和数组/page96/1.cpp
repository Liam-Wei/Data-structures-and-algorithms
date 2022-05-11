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

//实现括号匹配
void BracketMatch(Stack &s, char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        cout << str[i] << endl;
        //如果是左括号将其压入栈中
        if (str[i] == '[' || str[i] == '{' || str[i] == '(')
        {
            Push(s, str[i]);
        }
        else
        {
            //如果此时是右括号，而栈为空，则括号不匹配
            if (StackEmpty(s))
            {
                cout << "括号不匹配" << endl;
                return;
            }
            else
            {
                char chr = Pop(s);
                //如果栈不为空，但是栈顶元素与当前右括号不匹配
                if (!((str[i] == ']' && chr == '[') || (str[i] == '}' && chr == '{') || (str[i] == ')' && chr == '(')))
                {
                    cout << "括号不匹配" << endl;
                    return;
                }
            }
        }
        i++;
    }
    //如果全部匹配后，栈为空表示括号匹配
    if (StackEmpty(s))
    {
        cout << "括号匹配" << endl;
        return;
    }
    //栈中有多余括号，则不匹配
    cout << "括号不匹配" << endl;
}

int main()
{
    Stack s;
    char str[] = "[(){}]";

    BracketMatch(s, str);
}