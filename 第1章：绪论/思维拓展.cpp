#include <iostream>
using namespace std;

//采用递归实现斐波那契
int fn1(int n)
{
    if (n <= 1)
    {
        return 1;
    }

    return fn1(n - 1) + fn1(n - 2);
}

//采用非递归实现斐波那契
int fn2(int n)
{
    int fv1 = 1, fv2 = 1;

    while (n-- > 1)
    {
        int temp = fv2;
        fv2 += fv1;
        fv1 = temp;
    }

    return fv2;
}
int main()
{
    int n = 12;
    cout << fn1(n) << endl;
    cout << fn2(n) << endl;
}