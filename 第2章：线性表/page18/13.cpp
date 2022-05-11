#include <iostream>
#include <string.h>
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
int FindMin(SqList &L, int n)
{
    int i;
    int *B = new int[n];

    memset(B, 0, sizeof(int) * n);
    for (i = 0; i < n; i++)
    {
        if (L.data[i] > 0 && L.data[i] <= n)
        {
            B[L.data[i] - 1] = 1;
        }
    }
    for (i = 0; i < n; i++)
    {
        if (B[i] == 0)
        {
            break;
        }
    }
    return i + 1;
}

int main()
{
    SqList L;      // 创建一个顺序表
    ListInsert(L); // 插入写测试数据

    cout << FindMin(L, 5);
}