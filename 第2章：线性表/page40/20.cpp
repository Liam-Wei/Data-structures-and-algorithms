#include <iostream>
using namespace std;

typedef struct LNode
{
    int data;
    int freq = 0;
    struct LNode *pred;
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
        r = s;

        if (cin.get() == '\n')
        {
            break;
        }
    }

    r->next = L;
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

LNode *Locate(LinkList &L, int x)
{
    LNode *p, *q;
    p = L->next;

    while (p && p->data != x)
    {
        p = p->next;
    }

    if (!p)
    {
        return NULL;
    }

    else
    {
        p->freq++;
        if (p->pred == L || p->pred->freq > p->freq)
        {
            return p;
        }

        if (p->next != NULL)
        {
            p->next->pred = p->pred;
        }
        p->pred->next = p->next;
        q = p->pred;
        while (q != L && q->freq <= p->freq)
        {
            q = q->pred;
        }
        p->next = q->next;
        if (q->next != NULL)
        {
            q->next->pred = p;
        }
        p->pred = q;
        q->next = p;
    }

    return p;
}

int main()
{
    LinkList L = new LNode;

    TailInsert(L);

    LNode *p = Locate(L, 3);
}