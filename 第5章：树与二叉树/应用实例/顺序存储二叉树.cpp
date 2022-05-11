#include <iostream>
using namespace std;
#define MAXSIZE 100

//顺序存储结构
typedef struct BiTNode
{
    char data[MAXSIZE];
    int length = 0;
} BiTNode, *BiTree;

//创建二叉树
BiTree CreateTree(string s)
{
    BiTree T = new BiTNode;
    for (int i = 0; i < s.length(); i++)
    {
        T->data[i + 1] = s[i];
        T->length++;
    }
    return T;
}

//先序遍历
void PreOrderTraversal(BiTree T, int i)
{
    if (i <= T->length && T->data[i] != '#')
    {
        cout << T->data[i] << '\t';
        PreOrderTraversal(T, 2 * i);
        PreOrderTraversal(T, 2 * i + 1);
    }
}

int main()
{
    string s = "123#4#5##6#";
    BiTree T = CreateTree(s);
    PreOrderTraversal(T, 1);
}