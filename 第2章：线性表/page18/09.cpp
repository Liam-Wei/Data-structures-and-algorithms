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
void SearchList(SqList &L, int x)
{
    // 使用二分查找查找x
    int low = 0, high = L.length - 1, mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (L.data[mid] < x)
        {
            low = mid + 1;
        }
        else if (L.data[mid] > x)
        {
            high = mid - 1;
        }
        else
        {
            break;
        }
    }

    // 如果找到x，且不是最后一个元素进行交换
    if (L.data[mid] == x && mid != L.length - 1)
    {
        int temp = L.data[mid];
        L.data[mid] = L.data[mid + 1];
        L.data[mid + 1] = temp;
    }

    // 如果没有找到，进行插入
    if (low > high)
    {
        int i = 0;
        for (i = L.length - 1; i > high; i--)
        {
            L.data[i + 1] = L.data[i];
        }
        L.data[i + 1] = x;
        L.length++;
    }
}

int main()
{
    SqList L;      // 创建一个顺序表
    ListInsert(L); // 插入写测试数据

    SearchList(L, 3);
    PrintList(L);
}