#include <iostream>
using namespace std;

//快速排序
void swap(int *a, int i, int j)
{
    int temp = *(a + i);
    *(a + i) = *(a + j);
    *(a + j) = temp;
}

int sort(int *a, int i, int j)
{
    int pivot = *(a + i);
    int left = i + 1;
    int right = j;

    while (left <= right)
    {
        if (*(a + left) <= pivot)
        {
            left++;
        }
        else
        {
            swap(a, left, right);
            right--;
        }
    }

    swap(a, i, right);
    return right;
}

void quickSort(int *a, int left, int right)
{
    if (left < right)
    {
        int mid = sort(a, left, right);
        quickSort(a, left, mid - 1);
        quickSort(a, mid + 1, right);
    }
}

//找到数组种和为x的整数对
void Find(int *arr, int x, int n)
{
    int i = 0, j = n - 1; //定义两个指针，分别指向头部和尾部

    //只要两个指针没有相遇，继续
    while (i < j)
    {
        //如果首部+尾部元素小于x，将i++
        if (arr[i] + arr[j] < x)
        {
            i++;
        }
        //如果大于，将j--
        else if (arr[i] + arr[j] > x)
        {
            j--;
        }
        //如果相等，将其打印，然后将两个指针分别向后、向前偏移一位
        else
        {
            cout << arr[i] << " + " << arr[j] << " = " << x << endl;
            i++;
            j--;
        }
    }
}

int main()
{
    int arr[] = {1, 5, 3, 6, 2, 8, 3, 1, 4, 7, 9, 3, 2, 0, 2};
    quickSort(arr, 0, 14);
    Find(arr, 6, 15);
}