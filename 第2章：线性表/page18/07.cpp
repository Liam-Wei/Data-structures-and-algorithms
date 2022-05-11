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
void MergeList(SqList &L1, SqList &L2, SqList &L3)
{
    int i = 0, j = 0, k = 0;
    while (i < L1.length && j < L2.length)
    {
        if (L1.data[i] < L2.data[j])
        {
            L3.data[k++] = L1.data[i++];
        }
        else
        {
            L3.data[k++] = L2.data[j++];
        }
    }

    while (i < L1.length)
    {
        L3.data[k++] = L1.data[i++];
    }
    while (j < L2.length)
    {
        L3.data[k++] = L2.data[j++];
    }

    L3.length = L1.length + L2.length;
}

int main()
{
    SqList L1, L2, L3; // 创建一个顺序表
    ListInsert(L1);    // 插入写测试数据
    ListInsert(L2);

    MergeList(L1, L2, L3);
    cout << L3.length;

    PrintList(L3);
}