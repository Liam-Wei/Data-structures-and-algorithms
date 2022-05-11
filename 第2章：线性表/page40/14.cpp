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

void PublicNode(LinkList &LA, LinkList &LB, LinkList &LC)
{
    LNode *pa, *pb, *r; //定义两个链表的工作结点和尾插指针
    pa = LA->next;
    pb = LB->next;
    r = LC;

    while (pa && pb)
    {
        //小结点的链表向后移
        if (pa->data < pb->data)
        {
            pa = pa->next;
        }
        else if (pa->data > pb->data)
        {
            pb = pb->next;
        }
        //新建结点插入到LC尾部
        else
        {
            LNode *s = new LNode;
            s->data = pa->data;
            r->next = s;
            r = s;
            pa = pa->next;
            pb = pb->next;
        }
    }
    r->next = NULL;
}

int main()
{
    LinkList LA = new LNode;
    LinkList LB = new LNode;
    LinkList LC = new LNode;
    TailInsert(LA);
    TailInsert(LB);

    PublicNode(LA, LB, LC);
    Print(LC);
}