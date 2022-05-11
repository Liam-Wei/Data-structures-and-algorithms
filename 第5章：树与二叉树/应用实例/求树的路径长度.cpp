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

//定义全局变量，用于累加每个结点的路径长度
int path_length = 0;

//计算二叉树高度
void PathLength(BiTree &T, int count)
{
    if (T)
    {
        path_length += count;            //累加当前结点的路径长度
        PathLength(T->left, count + 1);  //递归左节点
        PathLength(T->right, count + 1); //递归右结点
    }
}

int main()
{
    int count = 0;
    BiTree T;
    // 124635
    // string chr = "12#46###3#5##";
    CreateTree(T);

    PathLength(T, 0);

    cout << path_length;
}