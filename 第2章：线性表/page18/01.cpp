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
bool DelMin(SqList &L, int &value)
{
    if (L.length == 0)
    {
        cout << "当前顺序表为空！";
        return false;
    }

    value = L.data[0];
    int pos = 0;

    // 循环遍历寻找最小值及最小值所在下标
    for (int i = 1; i < L.length; i++)
    {
        if (L.data[i] < value)
        {
            value = L.data[i];
            pos = i;
        }
    }

    // 使用最后一个位置填补删除元素
    L.data[pos] = L.data[L.length - 1];
    L.length--;

    return true;
}

int main()
{
    SqList L;      // 创建一个顺序表
    ListInsert(L); // 插入写测试数据
    PrintList(L);

    int value = 0;
    DelMin(L, value);
    PrintList(L);
    cout << "最小的元素为：" << value;
}