#include <iostream>
using namespace std;

typedef struct LNode
{
    int data;
    struct LNode *prior;
    struct LNode *next;
} LNode, *LinkList;

// 尾插法
void TailInsert(LinkList &L)
{
    int val = 0;
    LNode *r = L;
    while (cin >> val)
    {
        LNode *s = new LNode;
        s->data = val;
        r->next = s;
        s->prior = r;
        r = s;

        if (cin.get() == '\n')
        {
            break;
        }
    }

    r->next = L;
    L->prior = r;
}

// 遍历输出链表元素
void Print(LinkList L)
{
    LNode *p = L->next;
    while (p != L)
    {
        cout << p->data << '\t';
        p = p->next;
    }
    cout << endl;
}

void JudgeSymmetry(LinkList &L)
{
    LNode *p, *q; //定义工作结点，分别保存对应的前驱和后继
    p = L->next;
    q = L->prior;

    //二者不重合继续判断
    while (p != q)
    {
        //偶数元素情况
        if (p->next == q && p->data == q->data)
        {
            cout << "该循环链表对称" << endl;
            return;
        }

        //奇数情况
        if (p->data != q->data)
        {
            cout << "该循环链表不对称" << endl;
            return;
        }
        else
        {
            p = p->next;
            q = q->prior;
        }
    }
    cout << "该循环链表对称" << endl;
}

int main()
{
    LinkList L = new LNode;

    TailInsert(L);
    Print(L);

    JudgeSymmetry(L);
}