#include <iostream>
#include <string.h>
using namespace std;

typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkList;

// 头插法
void HeadInsert(LinkList &L)
{
    int val = '\0';
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

void ChangeList(LinkList &L)
{
    LNode *p, *q, *r, *s;
    p = q = L;

    while (q->next)
    {
        p = p->next;
        q = q->next;
        if (q->next != NULL)
        {
            q = q->next;
        }
    }
    q = p->next;
    p->next = NULL;
    while (q != NULL)
    {
        r = q->next;
        q->next = p->next;
        p->next = q;
        q = r;
    }
    s = L->next;
    q = p->next;
    p->next = NULL;
    while (q != NULL)
    {
        r = q->next;
        q->next = s->next;
        s->next = q;
        s = q->next;
        q = r;
    }
}

int main()
{
    LinkList L = new LNode;
    TailInsert(L);

    ChangeList(L);
    Print(L);
}