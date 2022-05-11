#include <iostream>
using namespace std;
#define MAXSIZE 100

//定义队列
typedef struct
{
    char data[MAXSIZE];
    int front = 0, rear = 0;
} Queue;

//判断队列是否为空
bool EmptyQueue(Queue Q)
{
    if (Q.front == Q.rear)
    {
        return true;
    }
    return false;
}

//判断队列是否已满
bool FullQueue(Queue Q)
{
    if (Q.rear == MAXSIZE)
    {
        return true;
    }
    return false;
}

//入队
void EnQueue(Queue &Q, char x)
{
    if (!FullQueue(Q))
    {
        Q.data[Q.rear++] = x;
    }
}

//出队
char DeQueue(Queue &Q)
{
    if (!EmptyQueue(Q))
    {
        return Q.data[Q.front++];
    }
    return '\0';
}

void Manager(Queue &ship, Queue &car, Queue &truck)
{
    int vehicles_num = 0, car_num = 0; //定义上船总数、客车数量
    char ch;                           //保存车辆编号

    while (vehicles_num < 10)
    {
        //如果客车未空，且还没上满4辆
        if (!EmptyQueue(car) && car_num < 4)
        {
            ch = DeQueue(car);
            EnQueue(ship, ch);
            car_num++;
            vehicles_num++;
        }
        //如果客车满4辆，同时货车未空，上一辆货车
        else if (car_num == 4 && !(EmptyQueue(truck)))
        {
            ch = DeQueue(truck);
            EnQueue(ship, ch);
            car_num = 0;
            vehicles_num++;
        }
        //如果客车空了，且不足4辆，使用货车补全
        else if (EmptyQueue(car) && car_num < 4)
        {
            while (vehicles_num < 10 && car_num < 4 && !EmptyQueue(truck))
            {
                ch = DeQueue(truck);
                EnQueue(ship, ch);
                car_num++;
                vehicles_num++;
            }
        }
        //货车空了，全部上客车
        else if (!EmptyQueue(car) && EmptyQueue(truck))
        {
            while (vehicles_num < 10 && car_num < 4 && !EmptyQueue(truck))
            {
                ch = DeQueue(truck);
                EnQueue(ship, ch);
                car_num++;
                vehicles_num++;
            }
        }
        //都空了
        if (EmptyQueue(car) && EmptyQueue(truck) && vehicles_num < 10)
        {
            cout << "客车与货车总数不足10" << endl;
            return;
        }
    }
}

//输出队列
void Print(Queue Q)
{
    while (!EmptyQueue(Q))
    {
        cout << DeQueue(Q) << '\t';
    }
    cout << endl;
}

int main()
{
    Queue ship, car, truck;
    EnQueue(car, 'C');
    EnQueue(car, 'C');
    EnQueue(car, 'C');
    EnQueue(car, 'C');
    EnQueue(car, 'C');
    EnQueue(car, 'C');
    EnQueue(truck, 'T');
    EnQueue(truck, 'T');
    EnQueue(truck, 'T');
    EnQueue(car, 'C');
    Manager(ship, car, truck);
    Print(ship);
}