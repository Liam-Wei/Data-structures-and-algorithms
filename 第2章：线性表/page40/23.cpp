#include <iostream>
using namespace std;

typedef struct LNode
{
    char data;
    struct LNode *next;
} LNode, *LinkList;

// 头插法
void HeadInsert(LinkList &L)
{
    char val = '\0';
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
    int val = '\0';
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
    int lena = 0, lenb = 0;
    LNode *p = LA->next;

    //获得LA长度
    while (p)
    {
        lena++;
        p = p->next;
    }
    p = LB->next;

    //获得LB长度
    while (p)
    {
        lenb++;
        p = p->next;
    }

    LNode *longList, *shortList; //定义两个指针分别表示长的和短的
    int dist = 0;
    if (lena > lenb)
    {
        longList = LA->next;
        shortList = LB->next;
        dist = lena - lenb;
    }
    else
    {
        longList = LB->next;
        shortList = LA->next;
        dist = lenb - lena;
    }

    //让长的先遍历几次，保持长的和短的链表同步
    while (dist--)
    {
        longList = longList->next;
    }

    while (longList != NULL)
    {
        //如果相等表示二者为公共结点
        if (longList == shortList)
        {
            break;
        }
        else
        {
            longList = longList->next;
            shortList = shortList->next;
        }
    }

    //将公共结点后的数据打印
    while (longList)
    {
        cout << longList->data << '\t';
        longList = longList->next;
    }
}

int main()
{
    LNode *p1 = new LNode;

    LNode *q1 = new LNode;
    LNode *q2 = new LNode;
    LNode *q3 = new LNode;

    // 公共结点
    LNode *m1 = new LNode;
    m1->data = 'm';
    LNode *m2 = new LNode;
    m2->data = 'n';

    m1->next = m2;
    m2->next = NULL;
    p1->next = m1;

    q1->next = q2;
    q2->next = q3;
    q3->next = m1;

    PublicNode(p1, q1);
}