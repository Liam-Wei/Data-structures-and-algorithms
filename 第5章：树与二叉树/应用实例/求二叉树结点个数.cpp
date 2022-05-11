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

//计算二叉树结点个数
void CountTNode(BiTree &T, int &count)
{
    if (T)
    {
        count++; //当前结点个数+1
        //递归左右子树
        CountTNode(T->left, count);
        CountTNode(T->right, count);
    }
}

int main()
{
    int count = 0;
    BiTree T;
    // 124635
    // string chr = "12#46###3#5##";
    CreateTree(T);
    CountTNode(T, count);
    cout << count << endl;
}