#include <iostream>
using namespace std;

//定义三元组
typedef struct
{
    int row;
    int col;
    int value;
} Triple[100];

//将稀疏数组存储到三元组
void ArrToTriple(int arr[][3], Triple t, int &len)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (arr[i][j] != 0)
            {
                t[len].row = i;
                t[len].col = j;
                t[len].value = arr[i][j];
                len++;
            }
        }
    }
}

//将三元组恢复成稀疏数组
void TripleToArr(int arr[][3], Triple t, int len)
{
    for (int i = 0; i < len; i++)
    {
        arr[t[i].row][t[i].col] = t[i].value;
    }
}

//打印二维数组
void Print(int arr[][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr[i][j] << '\t';
        }
        cout << endl;
    }
}

int main()
{
    int arr[3][3] = {{1, 0, 0}, {4, 0, 6}, {0, 8, 0}};
    Triple t;
    int len = 0;
    int new_arr[3][3] = {0};
    ArrToTriple(arr, t, len);
    TripleToArr(new_arr, t, len);
    Print(new_arr);
}