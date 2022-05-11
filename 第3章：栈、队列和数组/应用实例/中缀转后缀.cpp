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
        // cout << "当前栈已空" << endl;
        return '\0';
    }
    else
    {
        return s.data[s.top1--];
    }
}

//将中缀表达式转为后缀表达式
string InfixToSuffix(string infix)
{
    Stack s;
    string suffix = "";
    char op;

    for (int i = 0; i < infix.length(); i++)
    {
        //遇到操作数直接加入后缀表达式
        if (infix[i] >= 'A' && infix[i] <= 'Z')
        {
            suffix += infix[i];
        }
        //碰到左括号直接入栈
        else if (infix[i] == '(')
        {
            Push(s, infix[i]);
        }
        //碰到右括号依次弹出所有运算符将其加入后缀表达式
        else if (infix[i] == ')')
        {
            while (!StackEmpty(s))
            {
                op = Pop(s);
                if (op != '(')
                {
                    suffix += op;
                }
                else
                {
                    break;
                }
            }
        }

        else
        {
            //如果是乘号或者除号只弹出乘号或者除号
            if (infix[i] == '*' || infix[i] == '/')
            {

                while (!StackEmpty(s))
                {
                    op = Pop(s);
                    if (op == '(')
                    {
                        break;
                    }
                    else
                    {
                        //碰到低级运算符弹出再压回去
                        if (op == '+' || op == '-')
                        {
                            Push(s, op);
                            break;
                        }
                        else
                        {
                            suffix += op;
                        }
                    }
                }
            }
            //碰到+-运算符则将其所有运算符弹出
            else if (infix[i] == '+' || infix[i] == '-')
            {
                while (!StackEmpty(s))
                {
                    op = Pop(s);
                    if (op == '(')
                    {
                        break;
                    }
                    else
                    {
                        suffix += op;
                    }
                }
            }
            //将当前运算符压入栈中
            Push(s, infix[i]);
        }
    }

    //将栈中剩余运算符依次弹出
    while (!StackEmpty(s))
    {
        suffix += Pop(s);
    }

    return suffix;
}

int main()
{
    string infix = "A+B*(C-D)-E/F";
    cout << InfixToSuffix(infix);
}