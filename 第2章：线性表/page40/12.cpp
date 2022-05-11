#include <iostream>
using namespace std;

typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkList;

// 头插法
void HeadInsert(LinkList &L)
{
    int val = 0;
    while (cin >> val)
    {
        LNode *s = new LNode;
        s->data = val;
        s->next = L->next;
        L->next = s;

        if (cin.get() == '\n')
        {
            break;
        }
    }
}

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
        r = s;
        r->next = NULL;

        if (cin.get() == '\n')
        {
            break;
        }
    }
}

// 遍历输出链表元素
void Print(LinkList L)
{
    LNode *p = L->next;
    while (p)
    {
        cout << p->data << '\t';
        p = p->next;
    }
    cout << endl;
}

void Duplicate(LinkList &L)
{
    LNode *p, *pre; //分别保存工作结点和待删除结点前驱
    p = L->next, pre = L;

    while (p)
    {
        if (p->next && p->data == p->next->data) //判断当前结点和下一节点值是否相同需要保证后继结点存在
        {
            LNode *q = p;
            p = p->next;
            pre->next = p;
            delete q;
        }
        else
        {
            pre = p;
            p = p->next;
        }
    }
}

int main()
{
    LinkList L = new LNode;
    TailInsert(L);

    Duplicate(L);

    Print(L);
}