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
void DelValue(SqList &L, int x)
{
    int k = 0; //保存不等于x的元素的位置下标
    int length = L.length;
    for (int i = 0; i < length; i++)
    {
        // 如果不等于x，则将其赋值到k位置
        if (L.data[i] != x)
        {
            L.data[k++] = L.data[i];
        }
        // 等于x将其删除，就是将长度减一
        else
        {
            L.length--;
        }
    }
}

int main()
{
    SqList L;      // 创建一个顺序表
    ListInsert(L); // 插入写测试数据
    PrintList(L);

    int x = 5;
    DelValue(L, x);
    PrintList(L);
}