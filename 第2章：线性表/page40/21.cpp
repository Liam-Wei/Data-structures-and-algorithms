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

void LoopNode(LinkList &L)
{
    LNode *fast, *slow;    //定义两个快慢指针
    fast = slow = L->next; //分别指向首结点

    //同时遍历
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;       //每次走一步
        fast = fast->next->next; //每次走两步

        //相遇
        if (fast == slow)
        {
            break;
        }
    }

    if (fast == NULL || fast->next == NULL)
    {
        cout << "链表无环" << endl;
        return;
    }

    cout << "链表有环" << endl;
}

int main()
{
    LinkList L1 = new LNode;
    LinkList L2 = new LNode;
    LinkList L3 = new LNode;
    LinkList L4 = new LNode;

    L1->next = L2;
    L2->next = L3;
    L3->next = L4;
    L4->next = L2;

    LoopNode(L1);
}