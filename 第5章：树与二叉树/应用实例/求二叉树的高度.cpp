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

//计算二叉树高度
int TreeHeight(BiTree &T)
{
    if (T)
    {
        int left_height = TreeHeight(T->left);                                //左子树高度
        int right_height = TreeHeight(T->right);                              //右子树高度
        return (left_height > right_height ? left_height : right_height) + 1; //返回左右子树高度最大值+1
    }

    return 0;
}

int main()
{
    int count = 0;
    BiTree T;
    // 124635
    // string chr = "12#46###3#5##";
    CreateTree(T);

    cout << TreeHeight(T);
}