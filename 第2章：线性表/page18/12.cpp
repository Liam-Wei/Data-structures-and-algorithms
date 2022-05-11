#include <iostream>
using namespace std;
#define Maxsize 50

// 定义顺序表结构
typedef struct
{
    int data[Maxsize];
    int length = 0;
} SqList;

// 插入测试数据
void ListInsert(SqList &L)
{
    int val = 0;
    while (cin >> val)
    {
        L.data[L.length++] = val;

        if (cin.get() == '\n')
        {
            break;
        }
    }
}

// 打印顺序表
void PrintList(SqList L)
{
    for (int i = 0; i < L.length; i++)
    {
        cout << L.data[i] << '\t';
    }
    cout << endl;
}

// 题目功能函数
int MainValue(SqList &L, int n)
{
    int i, c, count = 1;
    c = L.data[0];
    for (i = 1; i < n; i++)
    {
        if (L.data[i] == c)
        {
            count++;
        }
        else
        {
            if (count > 0)
            {
                count--;
            }
            else
            {
                c = L.data[i];
                count = 1;
            }
        }
    }
    if (count > 0)
    {
        for (i = count = 0; i < n; i++)
        {
            if (L.data[i] == c)
            {
                count++;
            }
        }
    }
    if (count > n / 2)
    {
        return c;
    }
    else
    {
        return -1;
    }
}

int main()
{
    SqList L;      // 创建一个顺序表
    ListInsert(L); // 插入写测试数据

    cout << MainValue(L, 5);
}