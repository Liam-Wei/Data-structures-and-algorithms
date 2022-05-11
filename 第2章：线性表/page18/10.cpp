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
void Reverse(SqList &L, int left, int right)
{
    // 将对应位置元素交换实现数组逆转
    for (int i = 0; i < (right - left + 1) / 2; i++)
    {
        int temp = L.data[i + left];
        L.data[i + left] = L.data[right - i];
        L.data[right - i] = temp;
    }
}

void ReverseList(SqList &L, int p)
{
    Reverse(L, 0, p - 1);        // 逆转前m个元素
    Reverse(L, p, L.length - 1); // 逆转后n个元素
    Reverse(L, 0, L.length - 1); // 逆转整个数组
}

int main()
{
    SqList L;      // 创建一个顺序表
    ListInsert(L); // 插入写测试数据

    ReverseList(L, 3);
    PrintList(L);
}