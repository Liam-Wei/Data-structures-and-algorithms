#include <iostream>
#include <queue>
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

//层序遍历
void LevelOrderTraversal(BiTree &T)
{
    queue<BiTNode *> queue; //初始化一个队列
    BiTNode *p; //定义一个工作结点
    queue.push(T); //将根节点入队

    while (!queue.empty())
    {
        //获得队首元素
        p = queue.front();
        cout << p->data << '\t';
        queue.pop(); //将队首元素出队

        //将左孩子入队
        if (p->left)
        {
            queue.push(p->left);
        }
        //右孩子入队
        if (p->right)
        {
            queue.push(p->right);
        }
    }
}

int main()
{
    BiTree T;
    // 124635
    string chr = "12#46###3#5##";
    CreateTree(T);
    LevelOrderTraversal(T);
}