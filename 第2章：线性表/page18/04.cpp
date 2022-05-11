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
void DelValue(SqList &L, int s, int t)
{
    // 判断合理性
    if (s >= t || L.length == 0)
    {
        cout << "Error";
        return;
    }

    int i = 0, j = 0; // 定义保存第一个大于等于s的元素的下标，第一个大于t的元素的下标
    // 寻找第一个大于等于s的元素的下标
    for (; i < L.length && L.data[i] < s; i++)
        ;
    // 如果没有大于s的结束函数
    if (i == L.length)
    {
        return;
    }
    // 寻找第一个大于t的元素的下标
    for (; j < L.length && L.data[j] <= t; j++)
        ;
    // 将大于t的元素前移
    for (; j < L.length; i++, j++)
    {
        L.data[i] = L.data[j];
    }
    L.length = i;
}

int main()
{
    SqList L;      // 创建一个顺序表
    ListInsert(L); // 插入写测试数据
    PrintList(L);

    DelValue(L, 3, 6);
    PrintList(L);
}