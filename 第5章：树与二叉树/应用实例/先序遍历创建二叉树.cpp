#include <iostream>
using namespace std;

//创建树结点
typedef struct BiTNode
{
    char data;
    struct BiTNode *left, *right;
} BiTNode, *BiTree;

//通过先序遍历创建二叉树
void CreateTree(BiTree &T)
{
    char ch;
    cin >> ch;
    //如果检测为#，说明该节点为空
    if (ch == '#')
    {
        T = NULL;
    }
    else
    {
        if (!(T = new BiTNode)) //申请新结点空间
        {
            exit(0);
        }
        T->data = ch;
        //递归建立左右子树
        CreateTree(T->left);
        CreateTree(T->right);
    }
}

//先序遍历
void PreOrderTraversal(BiTree &T)
{
    if (T)
    {
        cout << T->data << '\t';
        //递归输出左右子树
        PreOrderTraversal(T->left);
        PreOrderTraversal(T->right);
    }
}

int main()
{
    BiTree T;
    // 124635
    string chr = "12#46###3#5##";
    CreateTree(T);
    PreOrderTraversal(T);
}