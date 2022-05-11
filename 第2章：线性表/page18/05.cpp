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

    // 定义k用于记录不在之间的元素个数
    int k = 0;
    for (int i = 0; i < L.length; i++)
    {
        if (!(L.data[i] >= s && L.data[i] <= t)) // 如果发现不在之间，则将其前移
        {
            L.data[k++] = L.data[i];
        }
    }

    L.length = k;
}

int main()
{
    SqList L;      // 创建一个顺序表
    ListInsert(L); // 插入写测试数据
    PrintList(L);

    DelValue(L, 3, 6);
    PrintList(L);
}