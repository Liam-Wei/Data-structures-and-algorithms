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

//寻找公共祖先结点
void CommonAncestor(BiTree T, int i, int j)
{
    //如果树不为空，且指定两个结点不为空
    if (T && T->data[i] != '#' && T->data[j] != '#')
    {
        //递归寻找公共结点
        while (i != j)
        {
            //如果i>j，则i变为其父结点
            if (i > j)
            {
                i = i / 2;
            }
            //否则，j变为父结点
            else
            {
                j = j / 2;
            }
        }
        //输出两结点相遇时
        cout << T->data[i] << endl;
    }
}

int main()
{
    string s = "123456###78";
    BiTree T = CreateTree(s);
    CommonAncestor(T, 10, 11);
}