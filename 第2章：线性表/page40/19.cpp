#include <iostream>
using namespace std;

typedef struct LNode
{
    int data;
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

void DelValue(LinkList &L)
{
    LNode *p, *pre, *minP, *minPre; //定义工作结点和保存最小值和前驱的指针

    //只要L不为空就搜索最小值
    while (L->next != L)
    {
        //重置指针
        p = minP = L->next;
        pre = minPre = L;

        while (p != L)
        {
            if (p->data < minP->data)
            {
                minP = p;
                minPre = pre;
            }
            pre = p;
            p = p->next;
        }

        cout << minP->data << '\t';
        minPre->next = minP->next; //删除最小值
        delete minP;
    }
    delete L;
}

int main()
{
    LinkList L = new LNode;

    TailInsert(L);

    DelValue(L);
}