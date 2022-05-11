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

void PublicNode(LinkList &LA, LinkList &LB)
{
    LNode *pa, *pb, *r, *q; //定义两个链表的工作结点和尾插指针
    pa = LA->next;
    pb = LB->next;
    r = LA;

    while (pa && pb)
    {
        //如果pa小于pb，则将其删除，同时指针后移
        if (pa->data < pb->data)
        {
            q = pa;
            pa = pa->next;
            delete q;
        }
        else if (pa->data > pb->data)
        {
            q = pb;
            pb = pb->next;
            delete q;
        }
        //如果相等将pa尾插，删除pb
        else
        {
            r->next = pa;
            r = pa;
            pa = pa->next;
            q = pb;
            pb = pb->next;
            delete q;
        }
    }

    //将剩余所有结点全部释放
    while (pa)
    {
        q = pa;
        pa = pa->next;
        delete q;
    }

    while (pb)
    {
        q = pb;
        pb = pb->next;
        delete q;
    }

    r->next = NULL;
    delete LB;
}

int main()
{
    LinkList LA = new LNode;
    LinkList LB = new LNode;

    TailInsert(LA);
    TailInsert(LB);

    PublicNode(LA, LB);
    Print(LA);
}