#include <iostream>
using namespace std;
#define MAXSIZE 100

//定义栈
typedef struct
{
    double data[MAXSIZE] = {0.0};
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
        // cout << "当前栈已空" << endl;
        return '\0';
    }
    else
    {
        return s.data[s.top1--];
    }
}

//计算后缀表达式
void CalSuffix(string suffix[])
{
    Stack s; //创建栈，用于保存操作数

    for (int i = 0; i < 15; i++)
    {
        //如果是运算数将其压入栈
        if (suffix[i] != "+" && suffix[i] != "-" && suffix[i] != "*" && suffix[i] != "/")
        {
            Push(s, atoi(suffix[i].c_str()));
        }
        //如果是操作符依次弹出两个操作数
        else
        {
            double oper1 = Pop(s); //右操作数
            double oper2 = Pop(s); //左操作数

            //执行相应运算，将运算结果压入栈中
            if (suffix[i] == "+")
            {
                Push(s, oper1 + oper2);
            }
            else if (suffix[i] == "-")
            {
                Push(s, oper2 - oper1);
            }
            else if (suffix[i] == "*")
            {
                Push(s, oper1 * oper2);
            }
            else if (suffix[i] == "/")
            {
                Push(s, oper2 / oper1);
            }
        }
    }
    //最终栈顶元素即为结果
    cout << "最终结果为：" << Pop(s) << endl;
}

int main()
{
    string suffix[] = {"15",
                       "7",
                       "1",
                       "1",
                       "+",
                       "-",
                       "/",
                       "3",
                       "*",
                       "2",
                       "1",
                       "1",
                       "+",
                       "+",
                       "-"};

    CalSuffix(suffix);
}