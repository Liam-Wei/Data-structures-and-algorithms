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

void BreakList(LinkList &LA, LinkList &LB)
{
    int i = 1;
    LNode *p, *ra, *rb;
    p = LA->next;
    ra = LA, rb = LB;
    ra->next = NULL, rb->next = NULL;
    while (p)
    {
        if (i % 2 == 1)
        {
            ra->next = p;
            ra = p;
        }
        else
        {
            rb->next = p;
            rb = p;
        }
        p = p->next;
        i++;
    }
    ra->next = NULL;
    rb->next = NULL;
}

int main()
{
    LinkList LA = new LNode;
    LinkList LB = new LNode;
    TailInsert(LA);

    BreakList(LA, LB);

    Print(LA);
    Print(LB);
}