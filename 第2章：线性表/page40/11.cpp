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
    LNode *p, *q, *ra; //工作指针、保存后继指针、LA尾指针
    LB->next = NULL;   //将LB链表置空
    p = LA->next;
    ra = LA; //初始化尾指针
    while (p)
    {
        // LA尾插
        ra->next = p;
        ra = p;
        p = p->next;

        //如果p不为空，继续将其前插到B
        if (p)
        {
            q = p->next; //保存p的后继，防止断链
            p->next = LB->next;
            LB->next = p;
            p = q;
        }
    }
    ra->next = NULL; //将A的尾结点的指针域置为空
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